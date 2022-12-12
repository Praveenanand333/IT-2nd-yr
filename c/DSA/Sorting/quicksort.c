#include<stdio.h>
void swap(int *x,int *y){
    int temp=*x;
    *x=*y;
    *y=temp;
}
int partition(int *a ,int  start,int end){
int pivot=a[end];
int partitiionindex=start;
int i;
for(i=start;i<end;i++){
if(a[i]<=pivot){
    swap(&a[i],&a[partitiionindex]);
    partitiionindex++;
}
}
swap(&a[partitiionindex],&a[end]);
return partitiionindex;
}
void quicksort(int *a,int start,int end){
    if(start<end){
        int partitionindex=partition(a,start,end);
        quicksort(a,start,partitionindex-1);
        quicksort(a,partitionindex+1,end);
    }
}
void main(){
    int a[10]={7,6,5,4,3,2,1,0};
    quicksort(a,0,7);
    int i;
    for(i=0;i<8;i++){
        printf("%d\n",a[i]);
    }
}