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
struct Bstnode* Min(struct Bstnode* root){
    struct Bstnode* current=root;
    while(current->left!=NULL){
        current=current->left;
    }
    return current;
}
struct Bstnode* Delete(struct Bstnode* root,int data){
if(root==NULL) return ;
else if(data<root->data)root->left=Delete(root->left,data);
else if(data>root->data)root->right=Delete(root->right,data);
else{//found the node to be deleted
//case-1 no child
if(root->left==NULL && root->right==NULL){
    free(root);
}
//case-2 with one child
else if(root->left==NULL){
    struct Bstnode* temp=root;
    root=root->right;
    free(temp);
}
else if(root->right==NULL){
    struct Bstnode* temp=root;
    root=root->left;
    free(temp);
}
//case -3 two child 
else{
    struct Bstnode* temp=Min(root->right);
    root->data=temp->data;
    root->right=Delete(root->right,temp->data);
}
//or we can find max of left sib tree and copy it then delete the duplicate node
}
return root;
}
void Traversal(struct Bstnode* current){
if(current==NULL) {
    return;
}

Traversal(current->left);  //b
printf("%d:",current->data);//a
Traversal(current->right);//c
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
   root= Insert(root,15);
   root= Insert(root,8);
   Traversal(root);
   Delete(root,30);
   printf("\n");
   Traversal(root);
  
   

}