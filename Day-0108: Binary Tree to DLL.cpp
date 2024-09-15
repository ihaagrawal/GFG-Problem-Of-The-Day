// Binary Tree to DLL (HARD)
// https://www.geeksforgeeks.org/problems/binary-tree-to-dll/1


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
 

// This function should return head to the DLL
class Solution {
  public:
  
    void solve(Node*& head, Node*& tail, Node* root){
        if(!root) return;
        
        solve(head, tail, root->left);
        if(!head) head = tail = root;
        else{
            tail->right = root;
            root->left = tail;
        }
        tail = root;
        solve(head, tail, root->right);
    }
  
    Node* bToDLL(Node* root) {
        Node* head = nullptr;
        Node* tail = nullptr;
        solve(head, tail, root);
        return head;
    }
};
