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
int Findheight(struct Bstnode* root){
    if(root==NULL){
        return -1;
    }
    else if(Findheight(root->left)>Findheight(root->right)){
        return Findheight(root->left)+1;
    }
    else{
        return Findheight(root->right)+1;
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
   int mini,maxi,h;
   mini=Min(root);
   maxi=Max(root);
   printf("the min element is :%d",mini);
   printf("\n");
   printf("the max element is :%d",maxi);
   printf("\n");
   h=Findheight(root);
   printf("the height of the tree is :%d",h);
    printf("\n");

   

}