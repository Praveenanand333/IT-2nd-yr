#include <stdio.h>
int i;
void disp(int arr[],int n){
for( i = 0; i < n; i++){
        printf("%d,", arr[i]);
    }
    printf("\n");
}


void reverse(int arr[],int n){
int temp;
for( i = 0; i<n/2; i++){
        temp = arr[i];
        arr[i] = arr[n-i-1];
        arr[n-i-1] = temp;
    }
}


int main(){
    int arr[6] = {1,2,3,4,5,6};
    int n=6;
    disp(arr,n);
    reverse(arr,n);
    disp(arr,n);
}
