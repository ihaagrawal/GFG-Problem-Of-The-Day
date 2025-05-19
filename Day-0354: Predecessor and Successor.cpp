// Predecessor and Successor (MEDIUM)
// https://www.geeksforgeeks.org/problems/predecessor-and-successor/1

/* BST Node
class Node
{
   public:
    int data;
    Node *left;
    Node *right;

    Node(int x){
        data = x;
        left = NULL;
        right = NULL;
    }
}; */

class Solution {
public:
    vector<Node*> findPreSuc(Node* root, int key) {
        Node* predecessor = nullptr;
        Node* successor = nullptr;
        Node* curr = root;

        while (curr) {
            if (curr->data < key) {
                predecessor = curr;
                curr = curr->right;
            } else curr = curr->left;
        }

        curr = root;
        while (curr) {
            if (curr->data > key) {
                successor = curr;
                curr = curr->left;
            } else curr = curr->right;
        }

        return {predecessor, successor};
    }
};
