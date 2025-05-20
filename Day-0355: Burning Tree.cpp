// Burning Tree (HARD)
// https://www.geeksforgeeks.org/problems/burning-tree/1

/*
class Node {
  public:
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
    int multiplier = 100000;
    int maxTime = 0;
    int maxDepthFromTarget = 0;
    int targetValue;

    long long int postorderTraversal(Node* currentNode) {
        if (currentNode == NULL) {
            return 0;
        }

        long long int leftSubtree = postorderTraversal(currentNode->left);
        long long int rightSubtree = postorderTraversal(currentNode->right);

        if (currentNode->data == targetValue) {
            maxTime = max(leftSubtree, rightSubtree);
            maxDepthFromTarget = maxTime;
            return multiplier;
        }

        if (leftSubtree >= multiplier || rightSubtree >= multiplier) {
            int depthFromTarget = 0;
            int propagationTime = 0;
            if (leftSubtree >= multiplier) {
                depthFromTarget = leftSubtree / multiplier;
                propagationTime = depthFromTarget + rightSubtree;
            } else if (rightSubtree >= multiplier) {
                depthFromTarget = rightSubtree / multiplier;
                propagationTime = depthFromTarget + leftSubtree;
            }

            maxTime = max(maxTime, max(maxDepthFromTarget, propagationTime));
            return (depthFromTarget + 1) * multiplier;
        }

        return max(leftSubtree, rightSubtree) + 1;
    }

    int minTime(Node* root, int target) {
        targetValue = target;
        postorderTraversal(root);
        return maxTime;
    }
};
