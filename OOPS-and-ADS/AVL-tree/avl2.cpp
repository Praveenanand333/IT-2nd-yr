// AVL tree implementation in C++

#include <iostream>
using namespace std;

struct Node {
   public:
  int key;
  Node *left;
  Node *right;
  int height;
};

class AVL{
public:
Node* root;


// Calculate height
int height(Node *N) {
  if (N == NULL)
    return 0;
  return N->height;
}

int max(int a, int b) {
  return (a > b) ? a : b;
}

// New node creation
Node *newNode(int key) {
  Node *node = new Node();
  node->key = key;
  node->left = NULL;
  node->right = NULL;
  node->height = 1;
  return (node);
}

// Rotate right
Node *rightRotate(Node *y) {
  Node *x = y->left;
  Node *T2 = x->right;
  x->right = y;
  y->left = T2;
  y->height = max(height(y->left),
          height(y->right)) +
        1;
  x->height = max(height(x->left),
          height(x->right)) +
        1;
  return x;
}

// Rotate left
Node *leftRotate(Node *x) {
  Node *y = x->right;
  Node *T2 = y->left;
  y->left = x;
  x->right = T2;
  x->height = max(height(x->left),
          height(x->right)) +
        1;
  y->height = max(height(y->left),
          height(y->right)) +
        1;
  return y;
}

// Get the balance factor of each node
int getBalanceFactor(Node *N) {
  if (N == NULL)
    return 0;
  return height(N->left) -
       height(N->right);
}

// Insert a node
Node *insertNode(Node *node, int key) {
  // Find the correct postion and insert the node
  if (node == NULL)
    return (newNode(key));
  if (key < node->key)
    node->left = insertNode(node->left, key);
  else if (key > node->key)
    node->right = insertNode(node->right, key);
  else
    return node;

  // Update the balance factor of each node and
  // balance the tree
  node->height = 1 + max(height(node->left),
               height(node->right));
  int balanceFactor = getBalanceFactor(node);
  if (balanceFactor > 1) {
    if (key < node->left->key) {
      return rightRotate(node);
    } else if (key > node->left->key) {
      node->left = leftRotate(node->left);
      return rightRotate(node);
    }
  }
  if (balanceFactor < -1) {
    if (key > node->right->key) {
      return leftRotate(node);
    } else if (key < node->right->key) {
      node->right = rightRotate(node->right);
      return leftRotate(node);
    }
  }
  return node;
}

// Node with minimum value
Node *nodeWithMimumValue(Node *node) {
  Node *current = node;
  while (current->left != NULL)
    current = current->left;
  return current;
}

// Delete a node
Node *deleteNode(Node *root, int key) {
  // Find the node and delete it	
  if (root == NULL)
    return root;
  if (key < root->key)
    root->left = deleteNode(root->left, key);
  else if (key > root->key)
    root->right = deleteNode(root->right, key);
  else {
    if ((root->left == NULL) ||
      (root->right == NULL)) {
      Node *temp = root->left ? root->left : root->right;
      if (temp == NULL) {
        temp = root;
        root = NULL;
      } else
        *root = *temp;
      free(temp);
    } else {
      Node *temp = nodeWithMimumValue(root->right);
      root->key = temp->key;
      root->right = deleteNode(root->right,
                   temp->key);
    }
  }

  if (root == NULL)
    return root;

  // Update the balance factor of each node and
  // balance the tree
  root->height = 1 + max(height(root->left),
               height(root->right));
  int balanceFactor = getBalanceFactor(root);
  if (balanceFactor > 1) {
    if (getBalanceFactor(root->left) >= 0) {
      return rightRotate(root);
    } else {
      root->left = leftRotate(root->left);
      return rightRotate(root);
    }
  }
  if (balanceFactor < -1) {
    if (getBalanceFactor(root->right) <= 0) {
      return leftRotate(root);
    } else {
      root->right = rightRotate(root->right);
      return leftRotate(root);
    }
  }
  return root;
}

// Print the tree
void printTree(Node *root) {
  if (root != nullptr) {
    printTree(root->left);
    cout << root->key << endl;
  
    printTree(root->right);
  }
}

int search(Node *temp,int ele){
if(temp==nullptr) return 0;
else if(temp->key==ele) return 1;
else if(temp->key<ele) return search(temp->right,ele);
else if(temp->key>ele) return search(temp->left,ele);

}
};
int main() {
  AVL tree;
  int choice,no,val,f;
  while(1){
  cout<<"1.Create a AVL treee\n2.Insert into avl tree\n3.search\n4.Show\n5.Delete";
  cin>>choice;
  switch(choice){
  case 1:
	  cout<<"Enter the number of nodes:";
	  cin>>no;
	  for(int i=0;i<no;i++){
	  cout<<"\nEnter the node values:";
	  cin>>val;
	  tree.root=tree.insertNode(tree.root,val);
	  }
	  cout<<"\nThe tree after creation is:\n";
	  tree.printTree(tree.root);
	  break;
  case 2:
	  cout<<"\nEnter the value to be inserted :";
	  cin>>val;
	  tree.root=tree.insertNode(tree.root,val);
	  cout<<"\nAVL tree after insertion is:";
	  tree.printTree(tree.root);
	  break;
  case 3:
  	cout<<"\nEnter the value to be searched:";
  	cin>>val;
  	f=tree.search(tree.root,val);
  	if(f==1){
  	cout<<"\nElement found\n";
  	}
  	else if(f==0){
  	cout<<"\nElement not found\n";
  	}
  	break;
  case 4:
    tree.printTree(tree.root);
  	break;
  case 5:
	  cout<<"\nEnter the value to be deleted:";
	  cin>>val;
	  tree.root=tree.deleteNode(tree.root,val);
	  cout<<"After deleting the AVL tree is:";
	  tree.printTree(tree.root);
	  break;
  
  }
  
  }

}
