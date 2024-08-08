// Sum Tree (MEDIUM)
// https://www.geeksforgeeks.org/problems/sum-tree/1

/*  Tree node
struct Node
{
    int data;
    Node* left, * right;
}; */

// Should return true if tree is Sum Tree, else false
class Solution {
  public:
    bool isSumTree(Node* root) {
        if(!root || (!root->left && !root->right)) return true;
        
        int left = 0, right = 0;
        if(root->left) left += root->left->data;
        if(root->right) right += root->right->data;
        
        bool result = (left+right == root->data);
        root->data += left + right;
        
        return result && isSumTree(root->left) && isSumTree(root->right);
    }
};
