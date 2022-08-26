//level order traaversal
//has some error and doesnot work
#include<stdio.h>
#include<conio.h>
struct Bstnode{
    int data;
    struct Bstnode* left;
    struct Bstnode* right;
};
struct Bstnode* Getnewnode(int data){
struct Bstnode* newnode=(struct  Bstnode*)malloc(sizeof(struct Bstnode*));
newnode->data=data;
newnode->left=newnode->right=NULL;
return newnode;
}
struct Bstnode* Insert(struct Bstnode* root,int data){
if(root==NULL){
    root=Getnewnode(data);
   
}
else if(data<=root->data){
    root->left=Insert(root->left,data);
}
else{
    root->right=Insert(root->right,data);
}
 return root;
}
struct Node{
    int data;
    struct Node*  next;

};
struct Node* front=NULL;
struct Node* rear=NULL;
void Push(struct Bstnode* root1){
    struct Node* temp=malloc(sizeof(struct Node*));
    temp=root1;
    if(front==NULL && rear==NULL){
        front=rear=temp;
        return; 
    }
    rear->next=temp;
    rear=temp;
}
void Pop(){
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
int Front(){
    struct Node* temp=front;
    printf("the front member in queue is:");
    printf("%d",front->data);
    printf("\n");
    return front->data;
}
void Rear(){
    struct Node* temp=rear;
    printf("the last member in queue is :");
    printf("%d",rear->data);
    printf("\n");
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
void Levelorder(struct Bstnode* root){
    if(root==NULL) return ;
    struct Node* q;
    Push(root);
    while(front!=NULL && rear!=NULL){
        struct Bstnode* current=Front();
        printf("%d",current->data);
        if(current->left!=NULL) Push(current->left);
        if(current->right!=NULL) Push(current->right);
        Pop();
   }

}
int main(){
    struct Bstnode* root=NULL;
    root=Insert(root,14);
   root= Insert(root,10);
   root= Insert(root,20);
   root= Insert(root,30);
   root= Insert(root,12);
   root= Insert(root,25);
   root= Insert(root,29);
   Levelorder(root);
   Print();

}
