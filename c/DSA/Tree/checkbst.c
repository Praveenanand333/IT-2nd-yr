#include<stdio.h>
#include<conio.h>
#include<math.h>
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
int Min(struct Bstnode* root){
    if(root==NULL){
        printf("error empty tree\n");
        return -1;
    }
    struct Bstnode* current=root;
    while(current->left!=NULL){
        current=current->left;
    }
    return current->data;
}
int Max(struct Bstnode* root){
    if(root==NULL){
        printf("error treee is empty\n");
        return -1;
    }
    struct Bstnode* current=root;
    while(current->right!=NULL){
        current=current->right;
    }
    return current->data;
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
    root= Insert(root,8);
    root= Insert(root,15);
   int mini,maxi,h;
   mini=Min(root->right);//minimum value of the right sub tree
   maxi=Max(root->left);//maximum value of the left sub tree
   if(maxi<root->data && mini>root->data){
    printf("the tree is binary search tree");
   }
   else{
    printf("the tree is not a binary search tree");
   }

   

}