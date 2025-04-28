// Maximum sum of Non-adjacent nodes (MEDIUM)
// https://www.geeksforgeeks.org/problems/maximum-sum-of-non-adjacent-nodes/1

// Node Structure
/*
struct Node
{
    int data;
    Node* left;
    Node* right;
};
*/

class Solution {
  public:
    // Function to return the maximum sum of non-adjacent nodes.
    pair<int, int> solve(Node* root) {
        if (!root) {
            return {0, 0};
        }
        
        pair<int, int> left = solve(root->left);
        pair<int, int> right = solve(root->right);
        
        int include = root->data + left.second + right.second;
        int exclude = max(left.first, left.second) + max(right.first, right.second);
        
        return {include, exclude};
    }
    
    int getMaxSum(Node* root) {
        pair<int, int> result = solve(root);
        return max(result.first, result.second);
    }
};
