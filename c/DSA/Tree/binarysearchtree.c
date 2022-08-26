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
int Search(struct Bstnode* root,int data){
if(root==NULL) return 0;
else if(data==root->data) return 1;
else if(data<=root->data) return Search(root->left,data);
else return Search(root->right,data);
}
int main(){
    struct Bstnode* root=NULL;
    root=Insert(root,14);
   root= Insert(root,10);
   root= Insert(root,20);
   int n;
   n=Search(root,10);
   if(n==1){
    printf("found");
   }
   else printf("not found");

}