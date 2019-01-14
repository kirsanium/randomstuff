#include <stdio.h>
#include <stdlib.h>
#include <mpi/mpi.h>
#include <math.h>

//#define size  1
#define INTERVALS_NUM 10
#define START       (-1.0)
#define END           1.0
#define ALPHA         100000
#define EPSILON       0.00000001

void fillMat(double mat[][INTERVALS_NUM + 1][INTERVALS_NUM + 1], int colFrom, int colTo, int size, int rankx);

void findNextPhi(double mat[][INTERVALS_NUM + 1][INTERVALS_NUM + 1], int x, int y, int z, double new_mat[][INTERVALS_NUM + 1][INTERVALS_NUM + 1],
                 double ready_mat[][INTERVALS_NUM + 1][INTERVALS_NUM + 1]);

int main(int argc, char** argv) {
    int size;
    MPI_Init(&argc, &argv);
    MPI_Comm_size(MPI_COMM_WORLD, &size);
    const int lastRank = size - 1;

    int dims[2] = {1, size};
    int periods[2] = {0, 0};
    int coords[2];
    int reorder = 1;
    MPI_Comm line;

    MPI_Cart_create(MPI_COMM_WORLD, 2, dims, periods, reorder, &line);
    MPI_Cart_get(line, 2, dims, periods, coords);
    int count = 0;
    int rankx = coords[1];

    int minCols = (INTERVALS_NUM  + 1) / size;
    int colFrom, colTo;
    if (rankx < (INTERVALS_NUM + 1) % size) {
        colFrom = (minCols + 1) * rankx;
        colTo = colFrom + minCols + 1;
    }
    else {
        colFrom = (minCols + 1) * ((INTERVALS_NUM + 1) % size) + minCols * (rankx - (INTERVALS_NUM + 1) % size);
        colTo = colFrom + minCols;
    }

    if (size != 1) {
        if (rankx == 0)
            colTo += 1;
        else if (rankx == lastRank)
            colFrom -= 1;
        else {
            colFrom -= 1;
            colTo += 1;
        }
    }

    double condition[size];
    condition[rankx] = 0.0;
    double cur_condition, max_condition = 0.0;

    double step = (END - START) / (double)INTERVALS_NUM;
    double ready_mat[colTo - colFrom][INTERVALS_NUM + 1][INTERVALS_NUM + 1];
    double (*mat0_p)[][INTERVALS_NUM+1][INTERVALS_NUM+1] = &ready_mat;
    for (int i = 0; i < colTo - colFrom; ++i)
        for (int j = 0; j < INTERVALS_NUM + 1; ++j)
            for (int k = 0; k < INTERVALS_NUM + 1; ++k)
                ready_mat[i][j][k] = (START + (colFrom+i) * step)*(START + (colFrom+i) * step) + (START + j * step)*(START + j * step) + (START + k * step)*(START + k * step);


    double mat[colTo - colFrom][INTERVALS_NUM + 1][INTERVALS_NUM + 1];
    double (*mat1_p)[][INTERVALS_NUM+1][INTERVALS_NUM+1] = &mat;
    fillMat(mat, colFrom, colTo, size, rankx);

    double new_mat[colTo - colFrom][INTERVALS_NUM + 1][INTERVALS_NUM + 1];
    double (*mat2_p)[][INTERVALS_NUM+1][INTERVALS_NUM+1] = &new_mat;
    fillMat(new_mat, colFrom, colTo, size, rankx);

    MPI_Request sendRq[2], rcvRq[2];

    do {
        count++;
        if (size == 1) {
            for (int i = 1; i < colTo - colFrom - 1; ++i) {
                for (int j = 1; j < INTERVALS_NUM; ++j) {
                    for (int k = 1; k < INTERVALS_NUM; ++k) {
                        findNextPhi(*mat1_p, i, j, k, *mat2_p, *mat0_p);
                    }
                }
            }
        }
        else {
            if (rankx == 0) {
                for (int j = 1; j < INTERVALS_NUM; ++j) {
                    for (int k = 1; k < INTERVALS_NUM; ++k) {
                        findNextPhi(*mat1_p, colTo - colFrom - 2, j, k, *mat2_p, *mat0_p);
                    }
                }
                MPI_Isend(&((*mat2_p)[colTo - colFrom - 2][0][0]), (INTERVALS_NUM + 1) * (INTERVALS_NUM + 1),
                          MPI_DOUBLE,
                          rankx + 1, 0, line, &sendRq[1]);
                MPI_Irecv(&((*mat2_p)[colTo - colFrom - 1][0][0]), (INTERVALS_NUM + 1) * (INTERVALS_NUM + 1),
                          MPI_DOUBLE,
                          rankx + 1, 0, line, &rcvRq[1]);
                for (int i = 1; i < colTo - colFrom - 2; ++i) {
                    for (int j = 1; j < INTERVALS_NUM; ++j) {
                        for (int k = 1; k < INTERVALS_NUM; ++k) {
                            findNextPhi(*mat1_p, i, j, k, *mat2_p, *mat0_p);
                        }
                    }
                }
                MPI_Wait(&sendRq[1], MPI_STATUS_IGNORE);
                MPI_Wait(&rcvRq[1], MPI_STATUS_IGNORE);
            } else if (rankx == lastRank) {
                for (int j = 1; j < INTERVALS_NUM; ++j) {
                    for (int k = 1; k < INTERVALS_NUM; ++k) {
                        findNextPhi(*mat1_p, 1, j, k, *mat2_p, *mat0_p);
                    }
                }
                MPI_Isend(&(*mat2_p)[1][0][0], (INTERVALS_NUM + 1) * (INTERVALS_NUM + 1), MPI_DOUBLE, rankx - 1, 0,
                          line,
                          &sendRq[0]);
                MPI_Irecv(&(*mat2_p)[0][0][0], (INTERVALS_NUM + 1) * (INTERVALS_NUM + 1), MPI_DOUBLE, rankx - 1, 0,
                          line,
                          &rcvRq[0]);
                for (int i = 2; i < colTo - colFrom - 1; ++i) {
                    for (int j = 1; j < INTERVALS_NUM; ++j) {
                        for (int k = 1; k < INTERVALS_NUM; ++k) {
                            findNextPhi(*mat1_p, i, j, k, *mat2_p, *mat0_p);
                        }
                    }
                }
                MPI_Wait(&sendRq[0], MPI_STATUS_IGNORE);
                MPI_Wait(&rcvRq[0], MPI_STATUS_IGNORE);
            } else {
                for (int j = 1; j < INTERVALS_NUM; ++j) {
                    for (int k = 1; k < INTERVALS_NUM; ++k) {
                        findNextPhi(*mat1_p, 1, j, k, *mat2_p, *mat0_p);
                        findNextPhi(*mat1_p, colTo - colFrom - 2, j, k, *mat2_p, *mat0_p);
                    }
                }
                MPI_Isend(&(*mat2_p)[1][0][0], (INTERVALS_NUM + 1) * (INTERVALS_NUM + 1), MPI_DOUBLE, rankx - 1, 0,
                          line,
                          &sendRq[0]);
                MPI_Irecv(&(*mat2_p)[0][0][0], (INTERVALS_NUM + 1) * (INTERVALS_NUM + 1), MPI_DOUBLE, rankx - 1, 0,
                          line,
                          &rcvRq[0]);
                MPI_Isend(&(*mat2_p)[colTo - colFrom - 2][0][0], (INTERVALS_NUM + 1) * (INTERVALS_NUM + 1), MPI_DOUBLE,
                          rankx + 1,
                          0, line, &sendRq[1]);
                MPI_Irecv(&(*mat2_p)[colTo - colFrom - 1][0][0], (INTERVALS_NUM + 1) * (INTERVALS_NUM + 1), MPI_DOUBLE,
                          rankx + 1, 0, line, &rcvRq[1]);
                for (int i = 2; i < colTo - colFrom - 2; ++i) {
                    for (int j = 1; j < INTERVALS_NUM; ++j) {
                        for (int k = 1; k < INTERVALS_NUM; ++k) {
                            findNextPhi(*mat1_p, i, j, k, *mat2_p, *mat0_p);
                        }
                    }
                }
                MPI_Wait(&sendRq[0], MPI_STATUS_IGNORE);
                MPI_Wait(&rcvRq[0], MPI_STATUS_IGNORE);
                MPI_Wait(&sendRq[1], MPI_STATUS_IGNORE);
                MPI_Wait(&rcvRq[1], MPI_STATUS_IGNORE);
            }
        }

        max_condition = 0.0;
        for (int i = 1; i < colTo - colFrom - 1; ++i) {
            for (int j = 1; j < INTERVALS_NUM; ++j) {
                for (int k = 1; k < INTERVALS_NUM; ++k) {
                    cur_condition = fabs((*mat2_p)[i][j][k] - (*mat1_p)[i][j][k]);
                    if (cur_condition > max_condition)
                        max_condition = cur_condition;
                }
            }
        }

        MPI_Allgather(&max_condition, 1, MPI_DOUBLE, condition, 1, MPI_DOUBLE, line);

        max_condition = 0.0;
        for (int i = 0; i < size; ++i) {
            if (condition[i] > max_condition)
                max_condition = condition[i];
        }

        if (mat1_p == &mat) {
            mat1_p = &new_mat;
            mat2_p = &mat;
        }
        else {
            mat1_p = &mat;
            mat2_p = &new_mat;
        }

        if (rankx == 0) printf("%.15f\n", max_condition);
        MPI_Barrier(line);

    } while (max_condition > EPSILON);
//
//
//    if (rankx == 0) {
//        for (int i = 0; i < colTo - colFrom; ++i) {
//            for (int j = 0; j < INTERVALS_NUM + 1; ++j) {
//                for (int k = 0; k < INTERVALS_NUM + 1; ++k) {
//                    printf("%5.2f ", (*mat1_p)[i][j][k]);
//                }
//                printf("\n");
//            }
//            printf("-------------\n");
//        }
//    }
//
//    MPI_Barrier(MPI_COMM_WORLD);
//
//    for (int r = 1; r < size; ++r) {
//        if (rankx == r) {
//            for (int i = 2; i < colTo - colFrom; ++i) {
//                for (int j = 0; j < INTERVALS_NUM + 1; ++j) {
//                    for (int k = 0; k < INTERVALS_NUM + 1; ++k) {
//                        printf("%5.2f ", (*mat1_p)[i][j][k]);
//                    }
//                    printf("\n");
//                }
//                printf("-------------\n");
//            }
//        }
//        MPI_Barrier(MPI_COMM_WORLD);
//    }

    MPI_Barrier(line);

    if (rankx == 0) printf("%d\n", count);

}

void findNextPhi(double mat[][INTERVALS_NUM + 1][INTERVALS_NUM + 1], int x, int y, int z,
                 double new_mat[][INTERVALS_NUM + 1][INTERVALS_NUM + 1], double ready_mat[][INTERVALS_NUM + 1][INTERVALS_NUM + 1])
{
    double h = (END - START) / INTERVALS_NUM;
    double ro = 6 - ALPHA * ready_mat[x][y][z];
    //double ro = 6 - ALPHA * (x*x+y*y+z*z);
    new_mat[x][y][z] = ((mat[x-1][y][z] + mat[x+1][y][z])/(h*h) + (mat[x][y-1][z] + mat[x][y+1][z])/(h*h) + (mat[x][y][z-1] + mat[x][y][z+1])/(h*h)
            - ro) / (6 / (h*h) + ALPHA);
}

void fillMat(double mat[][INTERVALS_NUM + 1][INTERVALS_NUM + 1], int colFrom, int colTo, int size, int rankx)
{
    double step = (END - START) / (double)INTERVALS_NUM;
    for (int i = 0; i < colTo - colFrom; ++i) {
        for (int j = 1; j < INTERVALS_NUM; ++j) {
            for (int k = 1; k < INTERVALS_NUM; ++k) {
                mat[i][j][k] = 0.0;
            }
        }
    }
    for (int i = 0; i < colTo - colFrom; ++i) {
        for (int j = 0; j < INTERVALS_NUM + 1; ++j) {
            mat[i][j][0] =
            mat[i][j][INTERVALS_NUM] =
                    (START + (colFrom + i) * step)*(START + (colFrom + i) * step) + (START + j * step)*(START + j * step) + 1;
        }
    }
    for (int i = 0; i < colTo - colFrom; ++i) {
        for (int k = 0; k < INTERVALS_NUM + 1; ++k) {
            mat[i][0][k] =
            mat[i][INTERVALS_NUM][k] =
                    (START + (colFrom + i) * step)*(START + (colFrom + i) * step) + (START + k * step)*(START + k * step) + 1;
        }
    }
    if (rankx == 0) {
        for (int j = 0; j < INTERVALS_NUM + 1; ++j)
            for (int k = 0; k < INTERVALS_NUM + 1; ++k)
                mat[0][j][k] = (START + j * step)*(START + j * step) + (START + k * step)*(START + k * step) + 1;
    }
    if (rankx == size - 1) {
        for (int j = 0; j < INTERVALS_NUM + 1; ++j)
            for (int k = 0; k < INTERVALS_NUM + 1; ++k)
                mat[colTo - colFrom - 1][j][k] = (START + j * step)*(START + j * step) + (START + k * step)*(START + k * step) + 1;
    }
}