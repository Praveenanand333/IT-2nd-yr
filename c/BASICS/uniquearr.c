#include<stdio.h>
void main(){
    int arr1[100],arr2[100],size1,size2=0,i,unique=0,j,flag=1;
    printf("enter the size of array");
    scanf("%d",&size1);
    for(i=0;i<size1;i++){
        printf("enter the element %d:",i+1);
        scanf("%d",&arr1[i]);
       
        
    }
for(i=0;i<size1;i++){
    flag=1;
    for(j=1;j<=size1-i;j++){
        
        if(arr1[i]==arr1[i+j]||arr1[i]==arr1[i-1]||arr1[i]==arr1[i-2]){
           flag=0;
          
            
        }}
        if(flag==1){
            printf("%d:",arr1[i]);
        }
        
        
    }


}