#include<stdio.h>
void main(){
int a=10;
int *p1;
int **p2;
p1=&a;
p2=&p1;
printf("%p:%p\n",p1,*p2);
printf("%p:%p\n",&p1,p2);
printf("%d:%d:%d\n",**p2,*p1,a);

}
