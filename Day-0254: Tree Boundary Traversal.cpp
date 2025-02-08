// Tree Boundary Traversal (MEDIUM)
// https://www.geeksforgeeks.org/problems/boundary-traversal-of-binary-tree/1


/*
// Tree Node
class Node {
  public:
    int data;
    Node* left;
    Node* right;

    // Constructor to initialize a new node
    Node(int val) {
        data = val;
        left = NULL;
        right = NULL;
    }
};
*/

class Solution {
  public:
    bool is_leaf(Node* root){
        if(!root->left && !root->right) return true;
        return false;
    }

    void add_left(Node* root, vector<int>& result){
        if(!root) return;
        Node* current = root->left;
        while(current){
            if(!is_leaf(current)) result.push_back(current->data);
            
            if(current->left) current = current->left;
            else current = current->right;
        }
    }
    
    void add_leaf(Node* root, vector<int>& result){
        if(is_leaf(root)){
            result.push_back(root->data);
            return;
        }   
        
        if(root->left) add_leaf(root->left, result);
        if(root->right) add_leaf(root->right, result);
    }
    
    void add_right(Node* root, vector<int>& result){
        vector<int> temp;
        Node* current = root->right;
        while(current){
            if(!is_leaf(current)) temp.push_back(current->data);
            
            if(current->right) current = current->right;
            else current = current->left;
        }
        
        for(int i=temp.size()-1;i>=0;i--) result.push_back(temp[i]);
    }

    vector <int> boundaryTraversal(Node *root) {
        vector<int> result;
        
        if(!root) return result;
        result.push_back(root->data);
        
        if(is_leaf(root)) return result;
        
        add_left(root, result);
        add_leaf(root, result);
        add_right(root, result);
        
        return result;
    }
};
