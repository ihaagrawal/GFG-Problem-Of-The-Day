// Fixing Two nodes of a BST (HARD)
// https://www.geeksforgeeks.org/problems/fixed-two-nodes-of-a-bst/1


/*
class Node
{
    public:
    int data;
    Node *left, *right;
    Node(int val)
    {
        data = val;
        left = right = NULL;
    }
};
*/

class Solution {
  public:
    void correctBST(Node* root) {
        Node *first = nullptr, *middle = nullptr, *last = nullptr, *prev = nullptr;

        function<void(Node*)> inorder = [&](Node* node) {
            if (!node) return;

            inorder(node->left);

            if (prev && node->data < prev->data) {
                if (!first) {
                    first = prev;
                    middle = node;
                } else last = node;
            }

            prev = node;
            inorder(node->right);
        };

        inorder(root);

        if (first && last) swap(first->data, last->data);
        else if (first && middle) swap(first->data, middle->data);
    }
};
