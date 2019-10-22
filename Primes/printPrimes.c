#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[])
{
    int vecino;
    int segundoVecino;

    scanf("%d", &vecino);
    fprintf(stderr, "%d\n", vecino);
    scanf("%d", &segundoVecino);
    while(segundoVecino != -1){
        if(segundoVecino%vecino != 0){
            printf("%d\n", segundoVecino);
        }
        scanf("%d", &segundoVecino);
    }
    printf("%d\n", -1);
}

