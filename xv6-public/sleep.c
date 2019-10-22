#include "types.h"
#include "stat.h"
#include "user.h"

int
main(int argc, char **argv)
{
    int i;
    if(argc>=2){
        printf(1,"A dormir \n");
        i = atoi(argv[1])*100;
        sleep(i);
    }
    printf(1,"Ya me desperte \n");



;
  exit();
}
