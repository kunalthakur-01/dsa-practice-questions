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


// solution 1 with n^2 time complexity
// int heightOfTree(node* root) {
//     if(root == NULL) {
//         return 0;
//     }

//     int left = heightOfTree(root -> left);
//     int right = heightOfTree(root -> right);

//     int ans = max(left, right) + 1;
//     return ans;

// }

// int diameterOfTree(node* root) {
//     if(root == NULL) {
//         return 0;
//     }

//     int op1 = diameterOfTree(root -> left);
//     int op2 = diameterOfTree(root -> right);
//     int op3 = heightOfTree(root -> left) + heightOfTree(root -> right) + 1;

//     int ans = max(op1, max(op2, op3));
//     return ans;
// }




// solution 2 with n time complexity

pair<int, int> diameter(node* root) {
    if(root == NULL){
        pair<int, int> p = make_pair(0,0);
        return p;
    }

    pair<int, int> left = diameter(root -> left);
    pair<int, int> right = diameter(root -> right);

    int opt1 = left.first;
    int opt2 = right.first;
    int opt3 = left.second + right.second + 1;

    pair<int, int> ans;
    ans.first = max(opt1, max(opt2, opt3));
    ans.second = max(left.second, right.second) + 1;

    return ans;
}

int diameterOfTree(node* root) {
    return diameter(root).first;
}



int main()
{
    node *root = NULL;
    
    root = buildTree(root);

   cout<< diameterOfTree(root);


    return 0;
}