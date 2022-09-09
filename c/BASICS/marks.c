#include<stdio.h>
void display(int sum,int average){
printf("The total and average are %d,%d",sum,average);
}



void calculate(int arr1[5]){
int j,sum=0,average,arr2[2];
for(j=0;j<5;j++){
sum+=arr1[j];
}
average=sum/5;
display(sum,average);
}



void getmarks(){
int i;
int arr1[5];
for(i=0;i<5;i++){
printf("enter the marks of subject %d",i);
scanf("%d",&arr1[i]);

}
calculate(arr1);
}



void main(){
getmarks();

}
