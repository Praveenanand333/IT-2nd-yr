#include<stdio.h>

void clgaddress(){
printf("College of Engineering guindy,Anna university\nGuindy\nChennai-25\n");
}

void homeaddress(){
printf("14,VOC nagar 3rd street\nEdayarpalayam \nCoimbatore-25\n");
}


void check(int n){
if(n%2==0){
clgaddress();
}
else{
homeaddress();
}
}


int input(){
int n;
printf("Enter the number:");
scanf("%d",&n);
check(n);
}


void main(){
input();
}
