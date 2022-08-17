#include<stdio.h>
#include<stdlib.h>
struct Node{
    int data;
    struct Node* link;
};
struct Node* top;
void Push(int x)
{
struct Node* temp=(struct Node*)malloc(sizeof(struct Node*));
temp->data=x;
temp->link=top;
top=temp;

}
void Pop(){
    struct Node* temp;
    if(top==NULL) return;
    temp=top;
    top=top->link;
    free(temp);

}
void Print(){
     struct Node* temp = top;
    printf("the list is :\n");
    while(temp!=NULL){
        printf("%d",temp->data);
        printf("\n");
        temp=temp->link;
    }
    printf("\n");
}
int main(){
    Push(1);
    Push(2);
    Push(3);
    Push(4);
    Push(5);
    Print();
    Pop();
    Print();

}