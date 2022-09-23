#include<stdio.h>

void count(){
static int flag=10;
flag++;
printf("%d\n",flag);
}


void main(){
int i;
for(i=0;i<4;i++){
count();
}
}
