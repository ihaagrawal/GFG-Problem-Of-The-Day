// Merge two BST 's (MEDIUM)
// https://www.geeksforgeeks.org/problems/merge-two-bst-s/1

/*
struct Node {
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
    void inorder(Node *root,vector<int>& temp){
        if(!root) return;
          
        inorder(root->left,temp);
        temp.push_back(root->data);
        inorder(root->right,temp);
    }
    
    vector<int> merge(Node *root1, Node *root2) {
        vector<int> temp1, temp2;
        inorder(root1,temp1);
        inorder(root2, temp2);
        vector<int> result;
        int i = 0, j = 0, n = temp1.size(), m = temp2.size();
        while(i < n and j < m){
            if(temp1[i] <= temp2[j]) result.push_back(temp1[i++]);
            else result.push_back(temp2[j++]);
        }
        while(i<n) result.push_back(temp1[i++]);
        while(j<m) result.push_back(temp2[j++]);
        
        return result;
    }
};
