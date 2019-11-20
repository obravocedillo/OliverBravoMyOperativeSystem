#include <fcntl.h>
#include <stdio.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>

typedef struct full_student{
    char firstName[20];
    char lastName[20];
    int prisionerId;
    char semester;
} Student;

void writeStudent(int argc, char **argv){
     char * filename = argv[1];

    int fd = open(filename, O_WRONLY | O_CREAT, 0666);
    for(int i = 0; i < 5; i++){
        Student myStudent;
        sprintf(myStudent.firstName, "juanito_%d",i);
        sprintf(myStudent.lastName, "perez_%d",i);
        myStudent.prisionerId = (i+1) * 10;
        myStudent.semester = (i+1);
        write(fd,&myStudent,sizeof(Student));
    }
    close(fd);
}

void readStudent(int argc, char **argv){
     char *filename = argv[1];
    int fd = open(filename,O_RDONLY);
    Student myStudent;
    int element = atoi(argv[2]);
    lseek(fd,element*sizeof(Student), SEEK_SET);
    read(fd,&myStudent,sizeof(Student));
    close(fd);
    printf("Student name: %s %s\n",myStudent.firstName, myStudent.lastName);
    printf("Id: %d, semester; %d", myStudent.prisionerId, myStudent.semester);
}

int main(int argc, char **argv){
   char *filename = argv[1];
   char *lastName = argv[2];
   char *newLastName = argv[3];
   int fd = open(filename,O_RDONLY);
   int posElement = -1;
   for(int i = 0; i < 5; i++){
       Student myStudent;
       read(fd, &myStudent, sizeof(Student));
       if(!strcmp(myStudent.lastName,lastName)){
           printf("ya lo encontre, es: %s %s \n", myStudent.firstName, myStudent.lastName);
           posElement = i;
           break;
        }
    }
    close(fd);
    if(posElement == -1){
        printf("Valor no encontrado \n");
    }else{
        Student myStudent;
        int lastNameMaxSize = sizeof(myStudent.lastName);
        char trunLastName [lastNameMaxSize];
        strncpy(trunLastName, newLastName, lastNameMaxSize);
        int fd = open(filename,O_WRONLY);
        lseek(fd, posElement*sizeof(Student) + sizeof(myStudent.firstName), SEEK_SET);
        write(fd,trunLastName,lastNameMaxSize);
        close(fd);
    }
} 