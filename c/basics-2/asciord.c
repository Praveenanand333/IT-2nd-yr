#include<stdio.h>
char asci(int x){
    return x;
}
int ord(char x){
    return x;
}
void main(){
    int n=65;
    char x='A';
   char m=asci(n);
   int y=ord(x);
   printf("the asci value of A is %d\n",y);
   printf("the  character of asci value 64 is %c",m);
}