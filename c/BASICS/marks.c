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
int i,markcredit[5];
int arr1[5],totcredit=18;
int creditarr={4,3,4,3,4};
int subname={"english","BEEE","maths","it essentials","c"};
for(i=0;i<5;i++){
printf("enter the marks of subject %s",subname[i]);
scanf("%d",&arr1[i]);
markredit[i]=creditarr[]
}
calculate(arr1);
}



void main(){
getmarks();

}
