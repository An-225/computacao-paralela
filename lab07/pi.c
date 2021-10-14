#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

int thread_count;
int n;
double sum;

void *Pth_mat_pi(void *rank);

int main(int argc, char *argv[])
{

    long thread;
    thread_count = strtol(argv[1], NULL, 10);
    n = strtol(argv[2], NULL, 10);
    pthread_t *thread_handles;
    thread_handles = malloc(thread_count * sizeof(pthread_t));
    for (thread = 0; thread < thread_count; thread++)
    {
        pthread_create(&thread_handles[thread], NULL, Pth_mat_pi, (void *)thread);
    }

    for (thread = 0; thread < thread_count; thread++)
    {
        pthread_join(thread_handles[thread], NULL);
    }

    free(thread_handles);

    printf("%f\n", 4 * sum);

    return 0;
}

void *Pth_mat_pi(void *rank)
{
    long my_rank = (long)rank;
    double factor;
    long long i;
    long long my_n = n / thread_count;
    long long my_first_i = my_n * my_rank;
    long long my_last_i = my_first_i + my_n;

    if (my_first_i % 2 == 0)
    {
        factor = 1.0;
    }
    else
    {
        factor = -1.0;
    }

    for (i = my_first_i; i < my_last_i; i++, factor = -factor)
    {
        sum += factor / (2 * i + 1);
    }

    return NULL;
}
