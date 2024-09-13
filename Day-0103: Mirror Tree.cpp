// Mirror Tree (EASY)
// https://www.geeksforgeeks.org/problems/mirror-tree/1

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

class Solution {
  public:
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
