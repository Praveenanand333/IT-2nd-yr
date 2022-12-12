//insert an element from unsorted array to its correct positon in sorted array
//1 7 8 5 2 6
//1 7 8 5 2 6
//1 5 7 8 2 6
//1 2 5 7 8 6
//1 2 5 6 7 8
#include<stdio.h>
void main(){

    int arr[10]={1,7,8,5,2,6};
    int i,len=0;
    for(len=0;arr[len]!='\0';len++){}
    for(i=1;i<len;i++){
        int current=arr[i];
        int j=i-1;
        while(arr[j]>current && j!=0){
            arr[j+1]=arr[j];
            j--;
        }
        arr[j+1]=current;
    }
    for(i=0;i<len;i++){
        printf("%d\n",arr[i]);
    }
}