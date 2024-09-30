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
  
    void inorder(vector<int>& arr, Node *root){
        if(!root) return;
        
        inorder(arr, root->left);
        arr.push_back(root->data);
        inorder(arr, root->right);
    }
  
    vector<int> merge(Node *root1, Node *root2) {
        vector<int> arr1, arr2;
        inorder(arr1, root1);
        inorder(arr2, root2);
        vector<int> result;
        
        int i = 0, j = 0;
        int n = arr1.size(), m = arr2.size();
        while(i < n && j < m){
            if(arr1[i] < arr2[j]){
                result.push_back(arr1[i]);
                i++;
            }else{
                result.push_back(arr2[j]);
                j++;
            }
        }
        
        while(i < n) result.push_back(arr1[i++]);
        while(j < m) result.push_back(arr2[j++]);
        
        return result;
    }
};
