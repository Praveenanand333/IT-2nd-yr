#include<stdio.h>
#include<stdlib.h>
struct  Node{
    int data;
    struct Node* next;
    struct Node* prev;
};
struct Node* head;
void InsertAtHead(int x){
    struct Node* newnode =(struct Node*)malloc(sizeof(struct Node));
    newnode->data=x;
    newnode->next=NULL;
    newnode->prev=NULL;
    if(head==NULL){
        head=newnode;
        return;
    }
    head->prev=newnode;
    newnode->next=head;
    head=newnode;

}
void Print(){
    struct  Node* temp=head;
    while(temp!=NULL){
        printf("%d",temp->data);
        temp=temp->next;
    };
    printf("\n");
}
void ReversePrint(){
    struct Node* temp=head;
    if(temp==NULL) return;//if empty list return
    //traversing to the last node 
    while(temp->next!=NULL){
        temp=temp->next;
    }
    //reverse printing using prev pointer
    while(temp!=NULL){
        printf("%d",temp->data);
        temp=temp->prev;
    }
    printf("\n");
}
int main(){
    InsertAtHead(1);
    InsertAtHead(2);
    InsertAtHead(3);
    InsertAtHead(4);
    InsertAtHead(5);
    Print();
    ReversePrint();

}