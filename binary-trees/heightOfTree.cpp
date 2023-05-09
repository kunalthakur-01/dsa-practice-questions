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

// approach 1
int heightOfTree(node* root) {
    if(root == NULL) {
        return 0;
    }

    int left = heightOfTree(root -> left);
    int right = heightOfTree(root -> right);

    int ans = max(left, right) + 1;
    return ans;
}

// approach 2
int treeHeight(node* root, int cnt, int height){
    if(root == NULL) {
        // cout<< cnt << " " << height << endl;
        if(cnt > height) height = cnt;
        return height;
    }
    
    cnt++;
    
    height = treeHeight(root -> left, cnt, height);
    
    height = treeHeight(root -> right, cnt, height);
    
    return height;
}


int main()
{
    node *root = NULL;
    
    root = buildTree(root);

   cout<< heightOfTree(root);


    return 0;
}