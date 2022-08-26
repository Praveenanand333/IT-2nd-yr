#include<stdio.h>
#include<conio.h>
struct Node
{
    int data;
    struct Node* next;//next is the pointer that points to the struct Node
    
};
struct Node* head;
void InsertAtBeginning(int x){
    struct Node* temp= malloc(sizeof(struct Node));
    temp->data=x;
    temp->next=head;
    head=temp;
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
    head=NULL;//making an empty list
    printf("How many numbers do you want to insert ?\n");
    int n,i,x;
    scanf("%d",&n);
    for(i=0;i<n;i++){
        printf("Enter the number \n");
        scanf("%d",&x);
    InsertAtBeginning(x);
    Print();}
}
