#include<stdio.h>
#include<stdlib.h>
struct Node
{
    int data;
    struct Node* next;
    
};

struct Node* head;
void InsertAtBeginning(int x){
    struct Node* temp= malloc(sizeof(struct Node));
    temp->data=x;
    temp->next=head;
    head=temp;
}


void InsertAtEnd(int x){
struct Node* temp= malloc(sizeof(struct Node));
 struct Node* temp1 = head;
    temp->data=x;
    temp->next=NULL;
    if(head==NULL){
head=temp;
return;
 }
    while (temp1->next!=NULL)
    {
        temp1=temp1->next;
    }
    temp1->next=temp;
}
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
int main(){
    int a;
    head=NULL;
    printf("How many numbers do you want to insert ?\n");
    int n,i,x;
    scanf("%d",&n);
    for(i=0;i<n;i++){
        printf("Enter the number \n");
        scanf("%d",&x);
    InsertAtEnd(x);
    }
    printf("\nEnter the number thst you want to insert at the beginning:");
    scanf("%d",&a);
    InsertAtBeginning(a);
    Print();
}
