#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

int thread_count = 3;
int A[6][6] = {{0, 1, 2, 3, 4, 5}, {2, 3, 4, 5, 6, 7}, {3, 4, 5, 6, 7, 8}, {4, 5, 6, 7, 8, 9}, {5, 6, 7, 8, 9, 10}, {6, 7, 8, 9, 10, 11}};
int x[6] = {2, 2, 2, 2, 2, 2};
int y[6];
int m = 6;
int n = 6;

void *Pth_mat_vect(void *rank);

void printMatriz()
{
	for (int l = 0; l < m; l++)
	{
		printf("|");
		for (int c = 0; c < n; c++)
		{
			printf("%d|", A[l][c]);
		}
		printf("\n");
	}
}

void printVetor(int*vet)
{
	printf("|");
	for (int i = 0; i < m; i++)
	{
		printf("%d|", vet[i]);
	}
	printf("\n");
}



int main(int argc, char *argv[])
{
	printMatriz();
	printf("\n");
	printVetor(x);
	printf("\n");
	printf("----------\n");


	long thread;
	pthread_t *thread_handles;
	thread_handles = malloc(thread_count * sizeof(pthread_t));
	for (thread = 0; thread < thread_count; thread++)
	{
		pthread_create(&thread_handles[thread], NULL, Pth_mat_vect, (void *)thread);
	}

	for (thread = 0; thread < thread_count; thread++)
	{
		pthread_join(thread_handles[thread], NULL);
	}

	free(thread_handles);
	
	printf("\n");
	printVetor(y);

	return 0;
}

void *Pth_mat_vect(void *rank)
{
	long my_rank = (long)rank;
	int i, j;
	int local_m = m / thread_count;
	int my_first_row = my_rank * local_m;
	int my_last_row = (my_rank + 1) * local_m - 1;

	for (i = my_first_row; i <= my_last_row; i++)
	{
		y[i] = 0.0;
		for (j = 0; j < n; j++)
		{
			y[i] += A[i][j] * x[j];
		}
	}

	return NULL;
}
