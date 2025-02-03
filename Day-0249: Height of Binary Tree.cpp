// Height of Binary Tree (EASY)
// https://www.geeksforgeeks.org/problems/height-of-binary-tree/1


/*
class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/
class Solution {
  public:
    // Function to find the height of a binary tree.
    int height(Node* node) {
        if (!node) return -1;
        
        int leftHeight = height(node->left);
        int rightHeight = height(node->right);
        
        return 1 + std::max(leftHeight, rightHeight);
    }
};
