#include<stdio.h>
int fact(int n){
    if(n==0||n==1){
        return 1;
    }
    else{
        return n*fact(n-1);
    }
}
void combination(int n,int r){
    int c;
    c=fact(n)/(fact(n-r)*fact(r));
    printf("%d",c);
}
void main(){
    int rows=6;
int i,j,k;
for(i=0;i<rows;i++){
    for(k=rows;k>i;k--){
        printf("\t");
    }
    for(j=0;j<=i;j++){
combination(i,j);
printf("\t");
printf("\t");
    }
    printf("\n");
}
}