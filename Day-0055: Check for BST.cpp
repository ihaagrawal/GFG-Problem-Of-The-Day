// Check for BST (EASY)
// https://www.geeksforgeeks.org/problems/check-for-bst/1


class Solution {
  public:
    void check(Node* &root, vector<int> &arr){
        if(root==NULL) return;
        
        check(root->left,arr);
        arr.push_back(root->data);
        check(root->right,arr);
    }
    
    bool isBST(Node* root) {
        vector<int> arr;
        check(root,arr);
        for(int i=0;i<arr.size();i++){
            if(arr[i]<=arr[i-1]){
                return false;
            }
        }
        return true;
    }
};
