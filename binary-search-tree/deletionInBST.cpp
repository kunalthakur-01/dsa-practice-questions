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

Node* deleteNode(Node* root, int val){
    if(root == NULL) return root;

    if(root -> data == val) {
        // case1: 0 child
        if(root -> left == NULL && root -> right == NULL){
            delete root;
            return NULL;
        }

        // case2: 1 child
          // left child
        if(root -> left != NULL && root -> right == NULL){
           Node* temp = root -> left;
           delete root;
           return temp;
        }
          // right child
        if(root -> left == NULL && root -> right != NULL){
           Node* temp = root -> right;
           delete root;
           return temp;
        }

        // case3: 2 child
        if(root -> left != NULL && root -> right != NULL){
            int mini = minNode(root -> right) -> data;
            root -> data = mini;
            root -> right = deleteNode(root -> right, mini);
            return root;
        }
    }

    else if(root -> data < val) {
        root -> right = deleteNode(root -> right, val);
        return root;
    }
    else {
        root -> left = deleteNode(root -> left, val);
        return root;
    }
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

    int target;

    cout << endl << "Enter the node to be deleted: ";
    cin >> target;

    root = deleteNode(root, target);

    cout << endl << "Inorder traversal: " << endl;
    inorder(root);
    return 0;
}