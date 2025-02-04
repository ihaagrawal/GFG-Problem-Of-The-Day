// Diameter of a Binary Tree (MEDIUM)
// https://www.geeksforgeeks.org/problems/diameter-of-binary-tree/1


/*
class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = NULL;
        right = NULL;
    }
};

Node* newNode(int val) {
    return new Node(val);
}
*/

class Solution {
  public:
    public:
    int diameter(Node* root) {
        int maxDiameter = 0;
        height(root, maxDiameter);
        return maxDiameter;
    }

  private:
    int height(Node* node, int& maxDiameter) {
        if (!node) return 0;

        int leftHeight = height(node->left, maxDiameter);
        int rightHeight = height(node->right, maxDiameter);

        maxDiameter = max(maxDiameter, leftHeight + rightHeight);

        return 1 + max(leftHeight, rightHeight);
    }
};
