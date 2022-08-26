 while(front!=NULL && rear!=NULL){
        struct Bstnode* current=Front();
        printf("%d",current->data);
        if(current->left!=NULL) Push(current->left->data);
        if(current->right!=NULL) Push(current->right->data);
        Pop();


   }