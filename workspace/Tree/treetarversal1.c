#include<stdio.h>
#include<conio.h>
//works perfectly
//preorder-a,b,c preorder-root,left,right
//inorder-b,a,c  inorder-left,root,right //inorder traversal will always give sorted array//if it is sorted array then we\
//can say that the tree is bst
//postorder-b,c,a  postorder-left,right,root
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
int Search(struct Bstnode* root,int data){
if(root==NULL) return 0;
else if(data==root->data) return 1;
else if(data<=root->data) return Search(root->left,data);
else return Search(root->right,data);
}
void Traversal(struct Bstnode* current){
if(current==NULL) {
    return;
}
printf("%d:",current->data);//a
Traversal(current->left);  //b
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
   

}