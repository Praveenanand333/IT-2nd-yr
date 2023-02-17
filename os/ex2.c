#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>

int main(int argc, char **argv){
printf("We are in ex2!!\n");
printf("Pid of the ex2 is %d\n",getpid());
return 0;
}
