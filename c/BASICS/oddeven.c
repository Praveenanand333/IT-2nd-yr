#include<stdio.h>
void main(){
int size,i;
printf("Enter the number of elements to be sstored in the array");
scanf("%d",&size);
int arr1[100];

for(i=0;i<size;i++){
    printf("\n enter the element %d",i);
    scanf("%d",&arr1[i]);
}
printf("the even elements are\n");
for(i=0;i<size;i++){
    
    if(arr1[i]%2==0){
        printf("%d:",arr1[i]);
    }
}
  printf("the odd elements are\n"); 
for(i=0;i<size;i++){
 
    if(arr1[i]%2!=0){
        printf("%d:",arr1[i]);
    }
}


}