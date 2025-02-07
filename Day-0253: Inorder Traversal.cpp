// Inorder Traversal (EASY)
// https://www.geeksforgeeks.org/problems/inorder-traversal/1


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
    // Function to return a list containing the inorder traversal of the tree.
    vector<int> inOrder(Node* root) {
        vector<int> result;
        Node* current = root;

        while (current != NULL) {
            if (current->left == NULL) {
                result.push_back(current->data);
                current = current->right;
            } else {
                Node* predecessor = current->left;
                while (predecessor->right != NULL && predecessor->right != current) {
                    predecessor = predecessor->right;
                }
                if (predecessor->right == NULL) {
                    predecessor->right = current;
                    current = current->left;
                } else {
                    predecessor->right = NULL;
                    result.push_back(current->data);
                    current = current->right;
                }
            }
        }

        return result;
    }
};
