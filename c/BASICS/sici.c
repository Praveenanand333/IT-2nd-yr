#include<stdio.h>
#include<math.h>
void simpleinterest(int principle,float rate,int time){
float si;
si=(principle*rate*time)/100;
printf("The simple interest is %f",si);
} 


void compundinterest(int principle,float rate,int time){
float ci;
ci=(principle*pow((1+(rate/100)),time))-principle;
printf("The compund interest is %f",ci);
}



void main(){
int principle,time;
float rate;
printf("Enter the principle amount:");
scanf("%d",&principle);
printf("\n Enter the rate");
scanf("%f",&rate);
printf("\n Enter the time in years");
scanf("%d",&time);
simpleinterest(principle,rate,time);
compundinterest(principle,rate,time);
}
