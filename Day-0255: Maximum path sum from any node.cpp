// Maximum path sum from any node (MEDIUM)
// https://www.geeksforgeeks.org/problems/maximum-path-sum-from-any-node/1


/*
// Tree Node
class Node {
public:
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/
class Solution {
  public:
    // Function to return maximum path sum from any node in a tree.
    int solve(Node* root, int& max_sum){
        if(!root) return 0;
        
        int maxl = max(0, solve(root->left, max_sum));
        int maxr = max(0, solve(root->right, max_sum));
        
        int sum = maxl + maxr + root->data;
        max_sum = max(sum, max_sum);
        return max(maxl, maxr) + root->data;
    }
    
    int findMaxSum(Node* root){
        if(!root) return 0;
        int max_sum = INT_MIN;
        solve(root, max_sum);
        return max_sum;
    }
};
