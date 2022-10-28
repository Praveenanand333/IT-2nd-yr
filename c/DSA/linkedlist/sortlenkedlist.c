#include<stdio.h>
#include<stdlib.h>
int arr[100];
int length=0;
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
void Arrsort(){
int i,j,k,length1=0;
int tempn;
for(length1=0;arr[length1]!='\0';length1++){}
for(j=0;j<length1;j++){
for(i=0;i<length1-1;i++){
if(arr[i]>arr[i+1]){
tempn=arr[i];
arr[i]=arr[i+1];
arr[i+1]=tempn;
}
}}

}
void Sort(){
int i=0;
struct Node* temp=head;
while(temp!=NULL){
arr[length]=temp->data;
length++;
temp=temp->next;
}
Arrsort();
struct Node* temp1=head;
while(temp1!=NULL){
temp1->data=arr[i];
i++;
temp1=temp1->next;
}
}

int main(){
    int a;
    head=NULL;
    int n,i,x;
    InsertAtEnd(4);
    InsertAtEnd(7);
    InsertAtEnd(5);
    InsertAtEnd(6);
    InsertAtBeginning(8);
    Print();
    Sort();
    Print();
}
