#include <bits/stdc++.h>
using namespace std;
class node
{
	public:
	int key;
	node *left, *right;
};

node* newNode(int key)
{
	node* Node = new node();
	Node->key = key;
	Node->left = Node->right = NULL;
	return (Node);
}

node *rightRotate(node *x)
{
	node *y = x->left;
	x->left = y->right;
	y->right = x;
	return y;
}


node *leftRotate(node *x)
{
	node *y = x->right;
	x->right = y->left;
	y->left = x;
	return y;
}

// This function brings the key at
// root if key is present in tree.
// If key is not present, then it
// brings the last accessed item at
// root. This function modifies the
// tree and returns the new root
node *splay(node *root, int key)
{

	if (root == NULL || root->key == key)
		return root;

	// Key lies in left subtree
	if (root->key > key)
	{
		// Key is not in tree,
		if (root->left == NULL) return root;

		// Zig-Zig (Left Left)
		if (root->left->key > key)
		{
			// First recursively bring the
			// key as root of left-left
			root->left->left = splay(root->left->left, key);

			// Do first rotation for root,
			// second rotation is done after else
			root = rightRotate(root);
		}
		else if (root->left->key < key) // Zig-Zag (Left Right)
		{
			// First recursively bring
			// the key as root of left-right
			root->left->right = splay(root->left->right, key);

			// Do first rotation for root->left
			if (root->left->right != NULL)
				root->left = leftRotate(root->left);
		}

		// Do second rotation for root
		return (root->left == NULL)? root: rightRotate(root);
	}
	else // Key lies in right subtree
	{
		// Key is not in tree, we are done
		if (root->right == NULL) return root;

		// Zig-Zag (Right Left)
		if (root->right->key > key)
		{
			// Bring the key as root of right-left
			root->right->left = splay(root->right->left, key);

			// Do first rotation for root->right
			if (root->right->left != NULL)
				root->right = rightRotate(root->right);
		}
		else if (root->right->key < key)// Zag-Zag (Right Right)
		{
			// Bring the key as root of
			// right-right and do first rotation
			root->right->right = splay(root->right->right, key);
			root = leftRotate(root);
		}

		// Do second rotation for root
		return (root->right == NULL)? root: leftRotate(root);
	}
}

node *insert(node *root, int k)
{
	if (root == NULL) return newNode(k);

	// Bring the closest leaf node to root
	root = splay(root, k);

	// If key is already present, then return
	if (root->key == k) return root;

	node *newnode = newNode(k);

	// If root's key is greater, make
	// root as right child of newnode
	// and copy the left child of root to newnode
	if (root->key > k)
	{
		newnode->right = root;
		newnode->left = root->left;
		root->left = NULL;
	}

	// If root's key is smaller, make
	// root as left child of newnode
	// and copy the right child of root to newnode
	else
	{
		newnode->left = root;
		newnode->right = root->right;
		root->right = NULL;
	}

	return newnode; // newnode becomes new root
}



node *search(node *root, int key)
{
    return splay(root, key);
}
void preOrder(node *root)
{
	if (root != NULL)
	{
		cout<<root->key<<" ";
		preOrder(root->left);
		preOrder(root->right);
	}
}

int main()
{
	node *root = newNode(100);
	root = insert(root, 25);
	root = insert(root, 35);
	root = insert(root, 5);
	root = insert(root, 10);
	root = insert(root, 20);
	root = insert(root, 200);
	cout<<"Preorder traversal of the modified Splay tree is \n";

	preOrder(root);
	root=search(root,5);
	cout<<"\n";
	cout<<"After searching 5";
	cout<<"\n";
	preOrder(root);
	return 0;
}


