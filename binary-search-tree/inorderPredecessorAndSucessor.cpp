#include<iostream>
using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int d) {
        this -> data = d;
        this -> left = NULL;
        this -> right = NULL;
    }
};

Node* minNode(Node* root){
    if(root == NULL) return NULL;
    
    if(root -> left == NULL) return root;
    
    Node* min = minNode(root -> left);
    
    return min;
}

Node* maxNode(Node* root){
    if(root == NULL) return NULL;
    
    if(root -> right == NULL) return root;
    
    Node* max = maxNode(root -> right);
    
    return max;
}

void inorderPredecessor(Node* root, int key, Node* &pre){
    if(root == NULL) {
        pre = NULL;
        return;
    }
    
    if(root -> data == key){
        if(root -> left != NULL){
            pre = maxNode(root -> left);
        }
    }
    
    else if(root -> data < key){
        pre = root;
        inorderPredecessor(root -> right, key, pre);
    }
    else {
        inorderPredecessor(root -> left, key, pre);
    }
    
    return;
}

void inorderSucessor(Node* root, int key, Node* &suc){
    if(root == NULL) {
        suc = NULL;
        return;
    }
    
    if(root -> data == key){
        if(root -> right != NULL){
            suc = minNode(root -> right);
        }
    }
    
    else if(root -> data < key){
        inorderSucessor(root -> right, key, suc);
    }
    else {
        suc = root;
        inorderSucessor(root -> left, key, suc);
    }
    
    return;
}

Node* insertNode(Node* root, int value){
    if(root == NULL) {
        root = new Node(value);
        return root;
    }

    if(value < root -> data) {
        root -> left = insertNode(root -> left, value);
    }
    else {
        root -> right = insertNode(root -> right, value);
    }

    return root;
}

void buildTree(Node* &root) {
    int value;
    cout << "enter the data" << endl;
    cin >> value;

    while(value != -1) {
        root = insertNode(root, value);
        cin >> value;
    }
}

void inorder(Node* root)
{
    if (!root) {
        return;
    }
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

int main() {
    Node* root = NULL;

    buildTree(root);

    cout << "Inorder traversal: " << endl;

    inorder(root);
    
    cout<< endl;

    cout<< "Minimum value in BST is " << minNode(root) -> data << endl;
    cout<< "Maximum value in BST is " << maxNode(root) -> data << endl;

    Node* pre = NULL;
    Node* suc = NULL;
    int key = 40;
    
    inorderPredecessor(root, key, pre);
    inorderSucessor(root, key, suc);
    
    cout << "Inorder predecesor of " << key << " is: " << pre -> data << endl;
    cout << "Inorder sucessor of " << key << " is: " << suc -> data;
    return 0;
}