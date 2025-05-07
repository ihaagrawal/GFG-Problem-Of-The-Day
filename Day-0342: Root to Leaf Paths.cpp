// Root to Leaf Paths (MEDIUM)
// https://www.geeksforgeeks.org/problems/root-to-leaf-paths/1

/*

Definition for Binary Tree Node
struct Node
{
    int data;
    struct Node* left;
    struct Node* right;

    Node(int x){
        data = x;
        left = right = NULL;
    }
};
*/

class Solution {
  public:
    void solve(Node* root, vector<vector<int>>& result, vector<int> temp){
        if(!root->left && !root->right){
            temp.push_back(root->data);
            result.push_back(temp);
            return;
        }
        
        temp.push_back(root->data);
        if(root->left) solve(root->left, result, temp);
        if(root->right) solve(root->right, result, temp);
        temp.pop_back();
    }
  
    vector<vector<int>> Paths(Node* root) {
        vector<vector<int>> result;
        if(!root) return result;
        vector<int> temp;
        
        solve(root, result, temp);
        return result;
    }
};
