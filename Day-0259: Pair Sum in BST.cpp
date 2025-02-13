// Pair Sum in BST (MEDIUM)
// https://www.geeksforgeeks.org/problems/find-a-pair-with-given-target-in-bst/1


/*
Node is as follows
class Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/

class Solution {
    public:
        bool findTarget(Node* root, int target) {
            unordered_set<int> seen;
            return findPair(root, target, seen);
        }

    private:
        bool findPair(Node* node, int target, unordered_set<int>& seen) {
            if (!node) return false;
            if (findPair(node->left, target, seen)) return true;
            if (seen.count(target - node->data)) return true;
            seen.insert(node->data);
            return findPair(node->right, target, seen);
        }
};
