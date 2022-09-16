#include<stdio.h>
#include<math.h>

void square(int n){
printf("The square of number %d is %d",n,n*n);
}

void cube(int n){
printf("The cube of the number %d is %d",n,n*n*n);

}

void squareroot(int n){
printf("The square root of number %d is %f",n,sqrt(n));
}


int input(){
int n;
printf("Enter the number:");
scanf("%d",&n);
square(n);
squareroot(n);
cube(n);
}


void main(){
input();
}
