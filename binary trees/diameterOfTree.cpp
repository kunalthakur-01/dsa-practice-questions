#include <iostream>
#include <algorithm>
using namespace std;

class node {
    public:
        int data;
        node* left;
        node* right;

    node(int d) {
        this -> data = d;
        this -> left = NULL;
        this -> right = NULL;
    }
};

node* buildTree(node* root) {

    cout << "Enter the data: " << endl;
    int data;
    cin >> data;
    root = new node(data);    

    if(data == -1) {
        return NULL;
    }

    cout << "Enter data for inserting in left of " << data << endl;
    root->left = buildTree(root->left);
    cout << "Enter data for inserting in right of " << data << endl;
    root->right = buildTree(root->right);
    return root;

}

int heightOfTree(node* root) {
    if(root == NULL) {
        return 0;
    }

    int left = heightOfTree(root -> left);
    int right = heightOfTree(root -> right);

    int ans = max(left, right) + 1;
    return ans;

}

int diameterOfTree(node* root) {
    if(root == NULL) {
        return 0;
    }

    int op1 = diameterOfTree(root -> left);
    int op2 = diameterOfTree(root -> right);
    int op3 = heightOfTree(root -> left) + heightOfTree(root -> right) + 1;

    int ans = max(op1, max(op2, op3));
    return ans;

}


int main()
{
    node *root = NULL;
    
    root = buildTree(root);

   cout<< diameterOfTree(root);


    return 0;
}