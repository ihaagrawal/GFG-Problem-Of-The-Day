// Mirror Tree (EASY)
// https://www.geeksforgeeks.org/problems/mirror-tree/1

/*
class Node {
public:
    int data;
    Node *left;
    Node *right;

    Node(int x) {
        data = x;
        left = right = NULL;
    }
};
*/

class Solution {
  public:
    // Function to convert a binary tree into its mirror tree.
    Node* solve(Node* node){
        if(!node) return nullptr;
        
        Node* left = solve(node->left);
        Node* right = solve(node->right);
        
        node->left = right;
        node->right = left;
        
        return node;
    }
    void mirror(Node* node) {
        solve(node);
    }
};
