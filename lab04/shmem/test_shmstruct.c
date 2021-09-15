/* test_shmat.c */
/* exemplo de utilizacao de shmat() 
* escrita num segmento de memoria compartilhada */
#include <errno.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ADDKEY 123
#define MSG "Mensagem escrita na memoria comum"

typedef struct
{
  int x;
  int y;
} Coord;


int main() {

  Coord *mycoords;
  int n = 10;
  int shmid ; /* identificador da memoria comum */
  int size = n * sizeof(Coord) ;
  //char *path="./test_shmstruct.c" ;

  int flag = 0;
/* recuperacao do shmid */
  if ((shmid = shmget(1001, size, IPC_CREAT|0600 )) == -1) {
        perror("Erro no shmget") ;
        exit(1) ; }
  printf("Sou o processo com pid: %d \n",getpid()) ;
  printf("Identificador do segmento recuperado: %d \n",shmid) ;

/* acoplamento do processo a zona de memoria */
  if ((mycoords = shmat (shmid, 0, flag)) == (Coord*)-1){
       perror("acoplamento impossivel") ;
       exit (1) ; }
/* escrita na zona de memoria compartilhada */
  mycoords[2].x=5;
  mycoords[2].y=10;
  sleep(1000);
  exit(0);
}

