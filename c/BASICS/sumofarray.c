#include<stdio.h>
void main(){
    int arr1[100],size,i,sum=0;
    printf("enter the size of array:");
    scanf("%d",&size);
    for(i=0;i<size;i++){
        printf("\n enter the element %d:",i);
        scanf("%d",&arr1[i]);
        sum+=arr1[i];
    }
printf("the sum of elements is %d",sum);
}