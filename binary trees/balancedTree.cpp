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


pair<bool, int> isBalanced(node* root) {
    if(root == NULL){
        pair<bool, int> p = make_pair(true,0);
        return p;
    }

    pair<bool, int> left = isBalanced(root -> left);
    pair<bool, int> right = isBalanced(root -> right);

    int leftAns = left.first;
    int rightAns = right.first;
    int diff = abs (left.second - right.second) <= 1;

    pair<bool, int> ans;
    ans.second = max(left.second, right.second) + 1;

    if(leftAns && rightAns && diff) {
        ans.first = true;
    }
    else {
        ans.first = false;
    }

    return ans;
}

int balancedTree(node* root) {
    return isBalanced(root).first;
}



int main()
{
    node *root = NULL;
    
    root = buildTree(root);

   cout<< balancedTree(root);


    return 0;
}