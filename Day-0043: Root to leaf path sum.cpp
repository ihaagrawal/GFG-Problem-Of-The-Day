// Root to leaf path sum (EASY)
// https://www.geeksforgeeks.org/problems/root-to-leaf-path-sum/1


/* A binary tree node
struct Node
{
    int data;
    Node* left, * right;
}; */

/*you are required to
complete this function */
class Solution {
  public:
    bool hasPathSum(Node *root, int target) {
        if(!root) return false;
        if(!root->left && !root->right) return target == root->data;
        
        int sum = target - root->data;
        return hasPathSum(root->left, sum) || hasPathSum(root->right, sum);
    }
};
