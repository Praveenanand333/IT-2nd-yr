#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>

int main(int argc, char **argv){
printf("Pid of ex1 is %d\n",getpid());
char* args[]={"hello","world","program",NULL};
execv("ex2",args);
//system("./ex2");
printf("Back to ex1");
return 0;

}
