#include <iostream>
using namespace std;
template <typename T>
class AVLTree {
public:
    struct Node {
        T data;
        int height;
        Node* left;
        Node* right;
        Node(T data) : data(data), height(1), left(nullptr), right(nullptr) {}
    };
    
    Node* root;

    Node* insert(Node* node, T data) {
        if (node == nullptr) {
            return new Node(data);
        }

        if (data < node->data) {
            node->left = insert(node->left, data);
        } else {
            node->right = insert(node->right, data);
        }

        node->height = std::max(getHeight(node->left), getHeight(node->right)) + 1;

        int balance = getBalance(node);

        if (balance > 1 && data < node->left->data) {
            return rotateRight(node);
        }

        if (balance < -1 && data > node->right->data) {
            return rotateLeft(node);
        }

        if (balance > 1 && data > node->left->data) {
            node->left = rotateLeft(node->left);
            return rotateRight(node);
        }

        if (balance < -1 && data < node->right->data) {
            node->right = rotateRight(node->right);
            return rotateLeft(node);
        }

        return node;
    }

    Node* deleteNode(Node* node, T data) {
        if (node == nullptr) {
            return node;
        }

        if (data < node->data) {
            node->left = deleteNode(node->left, data);
        } else if (data > node->data) {
            node->right = deleteNode(node->right, data);
        } else {
            if (node->left == nullptr || node->right == nullptr) {
                Node* temp = node->left ? node->left : node->right;

                if (temp == nullptr) {
                    temp = node;
                    node = nullptr;
                } else {
                    *node = *temp;
                }

                delete temp;
            } else {
                Node* temp = getMinNode(node->right);
                node->data = temp->data;
                node->right = deleteNode(node->right, temp->data);
            }
        }

        if (node == nullptr) {
            return node;
        }

        node->height = std::max(getHeight(node->left), getHeight(node->right)) + 1;

        int balance = getBalance(node);

        if (balance > 1 && getBalance(node->left) >= 0) {
            return rotateRight(node);
        }

        if (balance < -1 && getBalance(node->right) <= 0) {
            return rotateLeft(node);
        }

        if (balance > 1 && getBalance(node->left) < 0) {
            node->left = rotateLeft(node->left);
            return rotateRight(node);
        }

        if (balance < -1 && getBalance(node->right) > 0) {
            node->right = rotateRight(node->right);
            return rotateLeft(node);
        }

        return node;
    }

 

 int getHeight(Node* node) {
        if (node == nullptr) {
            return 0;
        } else {
            return node->height;
        }
    }
int getBalance(Node* node) {
        if (node == nullptr) {
            return 0;
        } else {
            return getHeight(node->left) - getHeight(node->right);
        }
    }
    
    Node* rotateRight(Node* node) {
        Node* left = node->left;
        Node* right = left->right;

        left->right = node;
        node->left = right;

        node->height = std::max(getHeight(node->left), getHeight(node->right)) + 1;
        left->height = std::max(getHeight(left->left), getHeight(left->right)) + 1;

        return left;
    }

    Node* rotateLeft(Node* node) {
        Node* right = node->right;
        Node* left = right->left;

        right->left = node;
        node->right = left;

        node->height = std::max(getHeight(node->left), getHeight(node->right)) + 1;
        right->height = std::max(getHeight(right->left), getHeight(right->right)) + 1;

        return right;
    }

    Node* rotateRightLeft(Node* node) {
        node->right = rotateRight(node->right);
        return rotateLeft(node);
    }

    Node* rotateLeftRight(Node* node) {
        node->left = rotateLeft(node->left);
        return rotateRight(node);
    }
 Node* getMinNode(Node *node) {
  Node *current = node;
  while (current->left != NULL)
    current = current->left;
  return current;
}void printTree(Node *root) {
  if (root != nullptr) {
    printTree(root->left);
    cout << root->data << endl;
  
    printTree(root->right);
  }
}

int search(Node *temp,T ele){
if(temp==nullptr) return 0;
else if(temp->data==ele) return 1;
else if(temp->data<ele) return search(temp->right,ele);
else if(temp->data>ele) return search(temp->left,ele);

}
};
int main() {
  AVLTree<int> tree;
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
	  tree.root=tree.insert(tree.root,val);
	  }
	  cout<<"\nThe tree after creation is:\n";
	  tree.printTree(tree.root);
	  break;
  case 2:
	  cout<<"\nEnter the value to be inserted :";
	  cin>>val;
	  tree.root=tree.insert(tree.root,val);
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
