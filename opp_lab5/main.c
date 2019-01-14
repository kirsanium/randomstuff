#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <mpi/mpi.h>
#include <stdbool.h>
#include <math.h>

#define TASKS_AMOUNT 500
#define NO_TASKS 0.0
#define FINISHING_TAG 99
/***********************************************/
/**                     TO DO                 **/
/** придумать, как нормально заканчиваться
 *  треду, который принимает сообщения
 */

//мьютекс
pthread_mutex_t mutex;
MPI_Comm world_dup;


//task list
double task_list[TASKS_AMOUNT];
int tasks_exist = TASKS_AMOUNT;
int last_task = TASKS_AMOUNT - 1;
int counter = 0;

void init_task_list(int rank);

//tasks thread
void* work(void* rank_size)
{
    double buf;
    int current_task = 0;

    bool to_end = false;
    int rank = *((int*)rank_size);
    int size = *((int*)rank_size + 1);
//    fprintf(stderr, "working thread started: rank %d, size %d\n", rank, size);
    int next_process;
    double wtf;
    while(1) {
        buf = NO_TASKS;
        next_process = (rank + 1) % size;
        pthread_mutex_lock(&mutex);
        while (tasks_exist) {
            --tasks_exist;
            pthread_mutex_unlock(&mutex);
            for (int i = 0; i < task_list[current_task]; ++i)
                for (int j = 0; j < task_list[current_task]; ++j)
                    wtf = sqrt(task_list[current_task]);
//            fprintf(stderr, "rank %d: task %d done; slept for %u\n", rank, counter, task_list[current_task]);
            ++counter;
            if (++current_task == TASKS_AMOUNT)
                current_task = 0;
            pthread_mutex_lock(&mutex);
        }
        pthread_mutex_unlock(&mutex);
        while (buf == NO_TASKS) {
            if (next_process == rank) {
                to_end = true;
                break;
            }
            MPI_Send(NULL, 0, MPI_INT, next_process, 0, MPI_COMM_WORLD);
            MPI_Recv(&buf, 1, MPI_DOUBLE, next_process, 1, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
            next_process = (next_process + 1) % size;
        }
        if (to_end) {
//            fprintf(stderr, "TO END %d\n", rank);
            break;
        }
        pthread_mutex_lock(&mutex);
        if (++last_task == TASKS_AMOUNT)
            last_task = 0;
        task_list[last_task] = buf;
        ++tasks_exist;
        pthread_mutex_unlock(&mutex);
    }
}

//message controlling thread
void* msg_recv(void* rank_size)
{
    int rank = ((int*)rank_size)[0];
    double no_tasks = NO_TASKS;
    MPI_Status status;
    do {
        MPI_Recv(NULL, 0, MPI_INT, MPI_ANY_SOURCE, 0, MPI_COMM_WORLD, &status);
        if (status.MPI_SOURCE != rank) {
            pthread_mutex_lock(&mutex);
            if (tasks_exist) {
                MPI_Send(&task_list[last_task], 1, MPI_DOUBLE, status.MPI_SOURCE, 1, MPI_COMM_WORLD);
//                fprintf(stderr, "Process %d sent task to process %d\n", rank, status.MPI_SOURCE);
                --last_task;
                --tasks_exist;
            } else {
                MPI_Send(&no_tasks, 1, MPI_DOUBLE, status.MPI_SOURCE, 1, MPI_COMM_WORLD);
//                fprintf(stderr, "Rank %d: no tasks msg sent\n", rank);
            }
            pthread_mutex_unlock(&mutex);
        }
    } while ( status.MPI_SOURCE != rank );
}

int main(int argc, char** argv)
{
    MPI_Init_thread(&argc, &argv, MPI_THREAD_MULTIPLE, NULL);
    int rank_size[2];
    MPI_Comm_size(MPI_COMM_WORLD, &rank_size[1]);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank_size[0]);
    int rank = rank_size[0];
    init_task_list(rank);

    pthread_attr_t attrs;
    pthread_t working_thread, msg_thread;

    pthread_mutex_init(&mutex, NULL);

    //инициализация атрибутов потока
    if(0 != pthread_attr_init(&attrs))
    {
        perror("Cannot initialize attributes");
        exit(1);
    };
    //установка атрибута "присоединенный"
    if(0 != pthread_attr_setdetachstate(&attrs, PTHREAD_CREATE_JOINABLE))
    {
        perror("Error in setting attributes");
        exit(2);
    }
    if(0 != pthread_create(&working_thread, &attrs, work, &rank_size))
    {
        perror("Cannot create working thread");
        exit(3);
    }
    if(0 != pthread_create(&msg_thread, &attrs, msg_recv, &rank_size))
    {
        perror("Cannot create message receiving thread");
        exit(4);
    }
    pthread_attr_destroy(&attrs);

    //ожидание завершения порожденных потоков
    pthread_join(working_thread, NULL);
    fprintf(stderr, "RIP working thread: rank %d\n", rank);
    MPI_Barrier(MPI_COMM_WORLD);
    MPI_Send(NULL, 0, MPI_INT, rank_size[0], 0, MPI_COMM_WORLD);

    pthread_join(msg_thread, NULL);
    fprintf(stderr, "RIP receiving thread, rank %d\n", rank);
    //MPI_Barrier(MPI_COMM_WORLD);
    pthread_mutex_destroy(&mutex);
    int taskscomplete = 0;

    MPI_Allreduce(&counter, &taskscomplete, 1, MPI_INT, MPI_SUM, MPI_COMM_WORLD);


    fprintf(stderr, "Goodbye from rank %d\n", rank);
    MPI_Barrier(MPI_COMM_WORLD);
    for (int i = 0; i < rank_size[1]; ++i) {
        if (rank == i)
            fprintf(stderr, "rank %d, tasks completed %d\n", rank, counter);
    }
    MPI_Finalize();
    return 0;
}

void init_task_list(int rank) {
//    fprintf(stderr, "hi\n");
    for (int i = 0; i < TASKS_AMOUNT; ++i)
        task_list[i] = ((double)i + 1) * (rank + 1);
}
