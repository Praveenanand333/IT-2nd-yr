#include<stdio.h>
void swap(int *p1,int *p2){
int temp;
temp=*p1;
*p1=*p2;
*p2=temp;
}
void main(){

int a=10;
int b=5;
printf("%d,%d\n",a,b);
swap(&a,&b);
printf("%d,%d\n",a,b);
}
