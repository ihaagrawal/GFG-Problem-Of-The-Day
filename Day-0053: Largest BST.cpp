// Largest BST (MEDIUM)
// https://www.geeksforgeeks.org/problems/largest-bst/1


/* Tree node structure  used in the program

struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};*/

class Solution{
    public:
    int count;
    
    vector<int> check(Node* root){
        if(!root) return {INT_MAX, INT_MIN, 0};
        
        vector<int> l = check(root->left);
        vector<int> r = check(root->right);
        
        if(l[1] < root->data && r[0] > root->data){
            count = max(count, 1 + l[2] + r[2]);
            return {min(l[0], root->data), max(r[1], root->data), 1+l[2]+r[2]};
        }
        
        return {INT_MIN, INT_MAX};
    }
    
    int largestBst(Node *root){
    	count = 1;
    	check(root);
    	return count;
    }
};
