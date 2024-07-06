// Populate Inorder Successor for all nodes (MEDIUM)
// https://www.geeksforgeeks.org/problems/populate-inorder-successor-for-all-nodes/1


class Solution {
  public:
    
    Node* temp = NULL;
    
    void populateNext(Node *root) {
        if(!root) return;
        
        populateNext(root->left);
        if(temp) temp->next = root;
        temp = root;
        populateNext(root->right);
    }
};
