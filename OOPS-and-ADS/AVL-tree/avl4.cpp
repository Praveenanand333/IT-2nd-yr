#include <iostream>
#include <algorithm>

using namespace std;

class Node {
public:
    int key;
    Node *left;
    Node *right;
    int height;

    Node(int k) {
        key = k;
        left = right = NULL;
        height = 1;
    }
};

class AVLTree {
public:
    Node *root;

    AVLTree() {
        root = NULL;
    }

    int height(Node *node) {
        if (node == NULL)
            return 0;
        return node->height;
    }

    int balanceFactor(Node *node) {
        if (node == NULL)
            return 0;
        return height(node->left) - height(node->right);
    }

    Node *rotateLeft(Node *node) {
        Node *rightChild = node->right;
        Node *leftSubtree = rightChild->left;

        rightChild->left = node;
        node->right = leftSubtree;

        node->height = 1 + max(height(node->left), height(node->right));
        rightChild->height = 1 + max(height(rightChild->left), height(rightChild->right));

        return rightChild;
    }

    Node *rotateRight(Node *node) {
        Node *leftChild = node->left;
        Node *rightSubtree = leftChild->right;

        leftChild->right = node;
        node->left = rightSubtree;

        node->height = 1 + max(height(node->left), height(node->right));
        leftChild->height = 1 + max(height(leftChild->left), height(leftChild->right));

        return leftChild;
    }

    Node *insert(Node *node, int key) {
        if (node == NULL)
            return new Node(key);

        if (key < node->key)
            node->left = insert(node->left, key);
        else if (key > node->key)
            node->right = insert(node->right, key);
        else
            return node;

        node->height = 1 + max(height(node->left), height(node->right));

        int balance = balanceFactor(node);

        if (balance > 1 && key < node->left->key)
            return rotateRight(node);

        if (balance < -1 && key > node->right->key)
            return rotateLeft(node);

        if (balance > 1 && key > node->left->key) {
            node->left = rotateLeft(node->left);
            return rotateRight(node);
        }

        if (balance < -1 && key < node->right->key) {
            node->right = rotateRight(node->right);
            return rotateLeft(node);
        }

        return node;
    }

    void print(Node *node, int space = 0) {
        if (node == NULL)
            return;

        space += 5;

        print(node->right, space);
        cout << endl;
        for (int i = 5; i < space; i++)
            cout << " ";
        cout << node->key << endl;
        print(node->left, space);
    }

    void insert(int key) {
        root = insert(root, key);
    }

    void print() {
        print(root, 0);
    }
};

int main() {
    AVLTree tree;

    tree.insert(10);
    tree.insert(20);
    tree.insert(30);
    tree.insert(40);
    tree.insert(50);
    tree.insert(25);

    tree.print();

    return

