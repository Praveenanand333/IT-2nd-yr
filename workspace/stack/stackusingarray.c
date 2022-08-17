#include<stdio.h>
int maxsize=101;
int a[101];
int top=-1;
void push(int x){
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
void print(){
    printf("the stack is:\n");
    for(int i =0;i<=top;i++){
        printf("%d",a[i]);
        printf("\n");
    }
}
int main(){
push(1);
push(2);
push(3);
push(4);
Top();
print();
pop();
Top();
print();
Top();
}

