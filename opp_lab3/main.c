#include <stdio.h>
#include <mpi/mpi.h>
#include <stdlib.h>

#define COMM_WIDTH 2
#define COMM_HEIGHT 2
#define WIDTH  4
#define HEIGHT 4
#define WH     4

void m_mul(const double* m1, const double* m2, int width, int height, int mid, double* m3)
{
    for (int i = 0; i < height; ++i) {
        for (int j = 0; j < width; ++j) {
            m3[i * width + j] = 0;
            for (int k = 0; k < mid; ++k)
                m3[i * width + j] += m1[i * mid + k] * m2[k * height + j];
        }
    }
}

//Current initialization is made for square matrices
void init_matA(double* matA)
{
//    for (int i = 0; i < HEIGHT * WH; ++i)
//        matA[i] = (double)(i+1);
    for (int i = 0; i < WH * WH; ++i)
        matA[i] = 0.0;

    for (int i = 0; i < WH; ++i)
        matA[i * WH + i] = 2.0;
}

void init_matB(double* matB)
{
//    for (int i = 0; i < WH * WIDTH; ++i)
//        matB[i] = (double)(i + 1);
    for (int i = 0; i < WH * WH; ++i)
        matB[i] = 1.0;
}

void print_mat(double* mat, int width, int height)
{
    for (int i = 0; i < height; ++i) {
        for (int j = 0; j < width; ++j) {
            printf("%.2f ", mat[i * width + j]);
        }
        printf("\n");
    }
    printf("\n");
}

int main(int argc, char** argv) {
    MPI_Init(&argc, &argv);

    int size;
    MPI_Comm_size(MPI_COMM_WORLD, &size);

    int dims[2] = {COMM_HEIGHT, COMM_WIDTH};
//    MPI_Dims_create(size, 2, dims);
//    int sizey = dims[0];
//    int sizex = dims[1];

    int periods[2] = {0, 0};
    int coords[2];
    int reorder = 1;
    MPI_Comm comm2d;

    MPI_Cart_create(MPI_COMM_WORLD, 2, dims, periods, reorder, &comm2d);
    MPI_Cart_get(comm2d, 2, dims, periods, coords);

    int ranky = coords[0];
    int rankx = coords[1];

    MPI_Comm line_comm, col_comm;

    double* matA = NULL;
    double* matB = NULL;

    if ((rankx == 0) && (ranky == 0))
    {
        matA = (double*)malloc(sizeof(double) * HEIGHT * WH);
        matB = (double*)malloc(sizeof(double) * WH * WIDTH);
        init_matA(matA);
        init_matB(matB);
        print_mat(matA, WH, HEIGHT);
        print_mat(matB, WIDTH, WH);
    }

    MPI_Comm_split(comm2d, ranky, rankx, &line_comm);
    MPI_Comm_split(comm2d, rankx, ranky, &col_comm);
    printf("sup\n");

    double* line   = (double*)malloc(sizeof(double) * WH * HEIGHT / COMM_HEIGHT);
    double* column = (double*)malloc(sizeof(double) * WH * WIDTH / COMM_WIDTH);

    if (rankx == 0)
    {
        MPI_Scatter(matA, WH * HEIGHT / COMM_HEIGHT, MPI_DOUBLE, line, WH * HEIGHT / COMM_HEIGHT, MPI_DOUBLE, 0, col_comm);
    }

    if (ranky == 0)
    {
        MPI_Datatype temp_column_datatype;
        MPI_Type_vector(WH, WIDTH / COMM_WIDTH, WIDTH, MPI_DOUBLE, &temp_column_datatype);
        MPI_Type_commit(&temp_column_datatype);
        MPI_Datatype column_datatype;
        MPI_Type_create_resized(temp_column_datatype, 0, sizeof(double) * WIDTH / COMM_WIDTH, &column_datatype);
        MPI_Type_commit(&column_datatype);
        MPI_Scatter(matB, 1, column_datatype, column, WH * WIDTH / COMM_WIDTH, MPI_DOUBLE, 0, line_comm);
        MPI_Type_free(&temp_column_datatype);
        MPI_Type_free(&column_datatype);
    }

    MPI_Bcast(line, WH * HEIGHT / COMM_HEIGHT, MPI_DOUBLE, 0, line_comm);
    MPI_Bcast(column, WH * WIDTH / COMM_WIDTH, MPI_DOUBLE, 0, col_comm);

    double* mul_result = (double*)malloc(sizeof(double) * HEIGHT / COMM_HEIGHT * WIDTH / COMM_WIDTH);
    m_mul(line, column, HEIGHT / COMM_HEIGHT, WIDTH / COMM_WIDTH, WH, mul_result);

    double* result = NULL;
    if ((rankx == 0) && (ranky == 0))
        result = (double*)malloc(sizeof(double) * HEIGHT * WIDTH);

    int displs[COMM_WIDTH * COMM_HEIGHT];
    for (int i = 0; i < COMM_HEIGHT; ++i) {
        for (int j = 0; j < COMM_WIDTH; ++j) {
            displs[i * COMM_WIDTH + j] = i * COMM_WIDTH * HEIGHT / COMM_HEIGHT + j;
        }
    }
    int recvcounts[COMM_WIDTH * COMM_HEIGHT];
    for (int i = 0; i < COMM_WIDTH * COMM_HEIGHT; ++i)
            recvcounts[i] = 1;
        //recvcounts[i] = HEIGHT / COMM_HEIGHT * WIDTH / COMM_WIDTH;

    MPI_Datatype temp_mul_result_datatype, mul_result_datatype;
    MPI_Type_vector(HEIGHT/COMM_HEIGHT, WIDTH/COMM_WIDTH, WIDTH, MPI_DOUBLE, &temp_mul_result_datatype);
    MPI_Type_commit(&temp_mul_result_datatype);
    MPI_Type_create_resized(temp_mul_result_datatype, 0, WIDTH / COMM_WIDTH * sizeof(double), &mul_result_datatype);
    MPI_Type_commit(&mul_result_datatype);

    //printf("sup\n");

    MPI_Gatherv(mul_result,
                HEIGHT/COMM_HEIGHT * WIDTH/COMM_WIDTH,
                MPI_DOUBLE, result,
                recvcounts, displs,
                mul_result_datatype, 0, comm2d);

    if ((rankx == 0) && (ranky == 0))
        print_mat(result, WIDTH, HEIGHT);

    free(line);
    free(column);

    if ((rankx == 0) && (ranky == 0))
    {
        free(matA);
        free(matB);
        free(result);
    }
    free(mul_result);

    MPI_Type_free(&temp_mul_result_datatype);
    MPI_Type_free(&mul_result_datatype);

    MPI_Finalize();
    return 0;
}