// Left View of Binary Tree (EASY)
// https://www.geeksforgeeks.org/problems/left-view-of-binary-tree/1


/* A binary tree node

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
    vector<int> result;
    map<int, int> mp;
    
    void solve(Node* root, int label){
        if(!root) return;
        if(mp.find(label) == mp.end()) mp[label] = root->data;
        
        solve(root->left, label + 1);
        solve(root->right, label + 1);
    }
  
    vector<int> leftView(Node *root) {
        if(!root) return {};
        solve(root, 0);
        for(auto it : mp) result.push_back(it.second);
        return result;
    }
};
