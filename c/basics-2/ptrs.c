#include<stdio.h>
void main(){
int a=10;
char b='#';
float c=3.14;
int *p1;
char *p2;
float *p3;
p1=&a;
p2=&b;
p3=&c;
printf("%p:%p\n",p1,&a);
printf("%p:%p\n",p2,&b);
printf("%p:%p\n",p3,&c);
printf("%d\n",*p1);
printf("%c\n",*p2);
printf("%f\n",*p3);
printf("%p\n",&p1);
printf("%p\n",&p2);
printf("%p\n",&p3);


}
