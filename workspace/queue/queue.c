#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
struct Node{
    int data;
    struct Node*  next;

};
struct Node* front=NULL;
struct Node* rear=NULL;
void Enqueue(int x){
    struct Node* temp=malloc(sizeof(struct Node*));
    temp->data=x;
    temp->next=NULL;
    if(front==NULL && rear==NULL){
        front=rear=temp;
        return; 
    }
    rear->next=temp;
    rear=temp;
}
void Dequeue(){
    struct Node* temp=front;
    if(front==NULL) return;
    if(front==rear){
        front=rear=NULL;
    }
    else{
        front=front->next;

    }
    free(temp);
}
void Print(){
    struct Node* temp = front;
    printf("the list is :\n");
    while(temp!=NULL){
        printf("%d",temp->data);
        printf("\n");
        temp=temp->next;
    }
    printf("\n");
}
void Front(){
    struct Node* temp=front;
    printf("the front member in queue is:");
    printf("%d",front->data);
    printf("\n");
}
void Rear(){
    struct Node* temp=rear;
    printf("the last member in queue is :");
    printf("%d",rear->data);
    printf("\n");
}
int main(){
    Enqueue(1);
     Enqueue(2);
      Enqueue(3);
       Enqueue(4);
        Enqueue(5);
        Print();
        Dequeue();
        Print();
        Front();
        Rear();
}

