#include<stdio.h>
void merge(int arr[],int l,int m,int r )
{
int i,j,k;
int n1=m-l+1;
int n2=r-m;
//create temp arrays
int L[n1],R[n2];
//copy the data to the temp arrays
for(i=0;i<n1;i++){
    L[i]=arr[l+i];
}
for(j=0;j<n2;j++){
    R[j]=arr[m+1+j];
}
//merge the arrays back into arr
i=0;//initial index of fist subarray
j=0;//initial  index of second subarray
k=l;//inital index of merged subarray
while (i<n1 && j<n2)
{
    if(L[i]<=R[j]){
        arr[k]=L[i];
        i++;
    }
    else{
        arr[k]=R[j];
        j++;
    }
    k++;
}

//copy the remaining elements of L  if there
while(i<n1){
    arr[k]=L[i];
    i++;
    k++;
}
//copy the remaining elements os R if there
while(j<n2){
    arr[k]=R[j];
    j++;
    k++;
}
}
void mergesort(int arr[],int l,int r){
    if(l<r){
        int m=l+(r-l)/2;
        mergesort(arr,l,m);
        mergesort(arr,m+1,r);
        merge(arr,l,m,r);
    }
}

void main(){
    int arr[10]={3,2,8,7,1,5};
    mergesort(arr,0,5);
    int i;
    for(i=0;i<5;i++){
        printf("%d\n",arr[i]);
    }
}