#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>

void replaceWord(char* pattern, char* newWord, int tmp, char *word ){
    if(strcmp(pattern, word) == 0){
        write(tmp, newWord, strlen(newWord));
        write(tmp, " ", 1);
    }else{
        write(tmp, word, strlen(word));
        write(tmp, " ", 1);
    }
}


int main(int argc, char **argv){
    char *pattern = argv[1];
    char *newWord = argv[2];
    char *fileName = argv[3];

    char c;
    char word[100];
    int n = 0;

    int fd = open(fileName, O_RDONLY);
    int fd2 = open("tmp.txt", O_WRONLY | O_CREAT, 0666);
    while(read(fd,&c,1)){
        if(c != ' '){
            word[n++] = c;
        } 
        else{
            word[n] = '\0';
            n = 0;
            //printf("word: %s\n", word);
            replaceWord(pattern, newWord, fd2, word);
        }
    }


    word[n] = '\0';
    if(strcmp(pattern, word) == 0){
        write(fd2, newWord, strlen(newWord));
    }else{
        write(fd2, word, strlen(word));
    }
    close(fd);
    close(fd2);

    unlink(fileName);
    link("tmp.txt", fileName);
    unlink("tmp.txt");

    //printf("Ultima palabra %s\n", word);
    return 0;
}