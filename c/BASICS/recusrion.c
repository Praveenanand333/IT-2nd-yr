#include<stdio.h>



int fact(int n){
if(n==0 || n==1){
return 1;
}
else{
return n*fact(n-1);
}
}   




void main(){
int n,factorial;
printf("Enter the number:");
scanf("%d",&n);
factorial=fact(n);
printf("\nThe factorial of the number %d is %d",n,factorial);
}
