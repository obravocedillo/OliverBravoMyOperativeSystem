#include <stdio.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <unistd.h>

int main(void) {
  int pid;
  pid = fork();
  if(pid == 0){
    int key = 27;
    int shmid = shmget(key,100,IPC_CREAT|0666);
    char * message = (char *)shmat(shmid,NULL,0);
    sprintf(message, "Hola mundo");
    while(message[0] == 'H'){
      sleep(1);
    } 
    printf("El mensajes final es: %s \n", message);
  } else {
    int key = 27;
    int shmid = shmget(key,100,IPC_CREAT|0666);
    char * message = (char *)shmat(shmid,NULL,0);
    sleep(1);
    printf("El mensajes es: %s \n", message);
    message[0] = '*';
    sleep(1);
  }
}
