<<<<<<< HEAD
#include <stdio.h>

int main(){
    printf("Hola Mundo");
=======
#include "./libhello.h"

int main(int argc, char **argv){
    int i = 0;
    for(i=1; i < argc; i++){
        printHello(argv[i]);
    }
>>>>>>> 8457314ab175b9417b5daa60d12eb4a87ddf0af9
    return 0;
}