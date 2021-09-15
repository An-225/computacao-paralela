/* test_shmaddr.c */
/* exemplo de utilizacao de shmat() 
* escrita num segmento de memoria compartilhada */
#include <errno.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h> 

int main () 
{
	int segment_id; 
	char* shared_memory; 
	struct shmid_ds shmbuffer; 
	int segment_size; 
	const int shared_segment_size = 0x6400; 
	char *path="./test_shmaddr.c" ;
	
	/* Allocate a shared memory segment. */ 
	segment_id = shmget (IPC_PRIVATE,shared_segment_size, IPC_CREAT|IPC_EXCL|S_IRUSR|S_IWUSR); 
	
	/* Attach the shared memory segment. */ 
	shared_memory = (char*) shmat (segment_id, 0, 0); 
	printf ("shared memory attached at address %p\n", shared_memory); 
	
	/* Show the segment's size. */ 
	shmctl (segment_id, IPC_STAT, &shmbuffer); 
	segment_size  =  shmbuffer.shm_segsz; 
	printf ("segment size: %d\n", segment_size);
	
	//fork();
	
	/* Show the segment's addr. */ 
	 printf ("shared memory attached at current ADDRESS %p\n", shared_memory); 
	
	/*Write a string to the shared memory segment*/ 
	  sprintf (shared_memory, "Hello, world."); 
	
	/*Detach the shared memory segment*/ 
	  shmdt (shared_memory); 
	
	/*Reattach the shared memory at a different address*/ 
	  shared_memory = (char*) shmat (segment_id, (void*) 0x5000000, 0); 
	  printf ("shared memory reattached at NEW ADDRESS %p\n", shared_memory); 
	
	/*Print out the string from shared memory.*/ 
	  printf ("%s\n", shared_memory); 

	//sleep(5);
	
	/*Detach the shared memory segment*/ 
	shmdt (shared_memory); 

	/*Deallocate the shared memory segment*/ 
	shmctl (segment_id, IPC_RMID, 0); 
	return 0; 

}
