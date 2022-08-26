#include<stdio.h>
#include<conio.h>
struct Node
{
    int data;
    struct Node* next;//next is the pointer that points to the struct Node
    
};
struct Node* head;
void Print(){
    struct Node* temp = head;
    printf("the list is :\n");
    while(temp!=NULL){
        printf("%d",temp->data);
        printf("\n");
        temp=temp->next;
    }
    printf("\n");
}
void Insertatpos(int data,int n){
    struct Node* temp1= malloc(sizeof(struct Node));//temp1 is the new node to be inserted
    temp1->data=data;
    temp1->next=NULL;
    if(n==1){
        temp1->next=head;
        head=temp1;
        return;

    }
    struct Node* temp2=head;
    for(int i =0;i<n-2;i++){
temp2=temp2->next;//temp2 is the node at the (n-1)th position
    }
    temp1->next=temp2->next;
    temp2->next=temp1;



}
void Delete(int n){
    struct Node* temp1=head;
    if(n==1){
        head=temp1->next;
        free(temp1);
        return;
    }
    for(int i=0;i<n-2;i++){
        temp1=temp1->next;
    }
    //temp1 points to the n-1 th node
struct Node* temp2=temp1->next;//temp2 points to the n th node which is to be deleted
temp1->next=temp2->next;//n+1 th node
free(temp2);
}
void main(){
    Insertatpos(5,1);
    Insertatpos(6,2);
    Insertatpos(7,3);
    Insertatpos(9,4);
    Insertatpos(8,4);
    Print();
    Delete(3);
    Print();

}