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

pair<int,bool> sumNode(node* root) {
    if(root == NULL) {
        pair<int,bool> ans = make_pair(0, true);
        return ans;
    }
    if(root -> left == NULL && root -> right == NULL) {
        pair<int,bool> ans = make_pair(root -> data, true);
        return ans;
    }
    
    pair<int,bool> leftValue = sumNode(root -> left);
    pair<int,bool> rightValue = sumNode(root -> right);
    
    pair<int,bool> ans;
    
    int sum = leftValue.first + rightValue.first;
    ans.first = sum + root -> data;
    
    if(sum == root -> data && leftValue.second && rightValue.second) ans.second = true;
    
    else ans.second = false;
    
    return ans;
}

node* buildTree(node* root) {

    cout << "Enter the data: ";
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


int main()
{
    node *root = NULL;
    
    root = buildTree(root);
    
    cout << sumNode(root).second;
    return 0;
}