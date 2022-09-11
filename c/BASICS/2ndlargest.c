#include<stdio.h>
int size,flag=0;
int largestelement(int arr1[size]){
int j;
int largestnumber=0;
for(j=0;j<size-flag;j++){
if(arr1[j]>largestnumber){
    largestnumber=arr1[j];
   
}
}
flag++;
return largestnumber;
}
void main(){
int arr1[100],i,largestnumber,arr2[100],index=0,secondlargest;
printf("enter the size of array");
scanf("%d",&size);
for(i=0;i<size;i++){
    printf("\n Enter the element %d:",i);
    scanf("%d",&arr1[i]);
}
largestnumber=largestelement(arr1);

for(i=0;i<size;i++){
    if(arr1[i]!=largestnumber){
        arr2[index]=arr1[i];
        index++;
    }
}

secondlargest=largestelement(arr2);
printf("The second largest element is  %d",secondlargest);
}