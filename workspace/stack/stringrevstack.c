#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int maxsize=101;
char a[101];
int top=-1;
void push(char x){
    if(top==maxsize-1){
        printf("error stack overflow");
        return;
    }
a[++top]=x;
}
void pop(){
    if(top==-1){
        printf("error empty stack");
        return;
    }
    top--;
}
void Top(){
    printf("the top element is:");
    printf("%d",a[top]);
    printf("\n");
}
void Reverse(char  *c,int n){
    int i=0;
for(i=0;i<=n;i++){
    a.push(c[i]);
}
int j=0;
for(j=0;j<n;j++){
    c[i]=a.Top();
    a.pop();
}
}
int main(){
    char string[51]="welcome";
    Reverse(string,strlen(string));
    printf("the reversed string is %s",string);
   
   
}
