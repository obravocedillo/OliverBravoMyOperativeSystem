#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <signal.h>
int infinito = 1;
void signalHandler(int signalNumber) {
    printf("Signal receive %d\n", signalNumber);
    infinito = 0;
}

int main (){
    int pid;
    signal(10,signalHandler);
    pid = fork();
    if (pid == 0) {
        printf("Soy el hijo\n");
        while(infinito){
            printf("No he salido\n");
            infinito = 2;
            sleep(2);
        }
        printf("Ya sali\n");
    } else {
        sleep(3);
        printf("Soy el padre\n");
        kill(pid,10);
        for(;;);
    }
}