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
    return 0;
}