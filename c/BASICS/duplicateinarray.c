#include<stdio.h>
void main(){
    int arr1[100],arr2[100],size1,size2=0,i,duplicate=0,j,index=0;
    printf("enter the size of array");
    scanf("%d",&size1);
    for(i=0;i<size1;i++){
        printf("enter the element %d:",i+1);
        scanf("%d",&arr1[i]);
       
        
    }
for(i=0;i<size1;i++){
    for(j=1;j<size1-i;j++){
        if(arr1[i]!=arr1[i-1]){
        if(arr1[i]==arr1[i+j]){
            duplicate++;
        }}
    }
}

printf("the number of duplicates is %d:",duplicate);
}