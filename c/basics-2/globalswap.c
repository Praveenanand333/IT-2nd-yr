#include<stdio.h>
int a=10;
int b=5;
void swap(){
a=a+b;
b=a-b;
a=a-b;
printf("%d,%d\n",a,b);
}
void main(){
printf("%d,%d\n",a,b);
swap();
}
