#include<stdio.h>
int i;

int largestnumberfinder(int arr1[6]){
int largestnumber=0;
for(i=0;i<6;i++){

if(largestnumber<arr1[i]){
largestnumber=arr1[i];
}
}

return largestnumber;

}

void main(){
int largestelement=0;
int arr1[6]={1,2,3,4,5,6};
largestelement=largestnumberfinder(arr1);
printf("%d",largestelement);
}
