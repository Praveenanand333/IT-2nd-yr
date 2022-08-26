#include<stdio.h>
void main(){
int sec,min,hr;
printf("enter the no of seconds");
scanf("%d",&sec);
hr=sec/3600;
min=(sec%3600)/60;
printf("\n the hours and minuites are %d,%d",hr,min);
getch();
}