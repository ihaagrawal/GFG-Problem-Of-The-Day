// Root to leaf paths sum (MEDIUM)
// https://www.geeksforgeeks.org/problems/root-to-leaf-paths-sum/1

/* Tree node structure  used in the program
 struct Node
 {
     int data;
     Node* left, *right;
}; */

class Solution {
  public:
  
    void solve(Node *root, int &sum){
        if(!root->left && !root->right){
            sum = sum + root->data;
            return;
        }
        
        if(root->left){
            root->left->data = (root->data * 10) + root->left->data;
            solve(root->left, sum);
        }
        
        if(root->right){
            root->right->data = (root->data * 10) + root->right->data;
            solve(root->right, sum);
        }
        
    }
  
    int treePathsSum(Node *root) {
        int sum = 0;
        solve(root, sum);
        return sum;
    }
};
