// k-th Smallest in BST (MEDIUM)
// https://www.geeksforgeeks.org/problems/find-k-th-smallest-element-in-bst/1


/*Complete the function below

struct Node {
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
    // Return the Kth smallest element in the given BST
    int kthSmallest(Node *root, int k) {
        stack<Node*> st;
        Node* current = root;
        int count = 0;

        while (!st.empty() || current != NULL) {
            while (current != NULL) {
                st.push(current);
                current = current->left;
            }

            current = st.top();
            st.pop();
            count++;

            if (count == k) return current->data;

            current = current->right;
        }

        return -1;
    }
};
