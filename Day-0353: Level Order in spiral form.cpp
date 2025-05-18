// Level Order in spiral form (EASY)
// https://www.geeksforgeeks.org/problems/level-order-traversal-in-spiral-form/1

{
    int data;
    Node* left;
    Node* right;

    Node(int x){
        data = x;
        left = right = NULL;
    }
}; */
class Solution {
public:
    vector<int> findSpiral(Node* root) {
        vector<int> result;
        if (!root) return result;

        // Two stacks for alternating levels
        stack<Node*> s1; // For even levels (right to left)
        stack<Node*> s2; // For odd levels (left to right)

        s1.push(root);

        while (!s1.empty() || !s2.empty()) {
            // Process all nodes in s1
            while (!s1.empty()) {
                Node* current = s1.top();
                s1.pop();
                result.push_back(current->data);

                // Push children to s2 (right first for even level)
                if (current->right) s2.push(current->right);
                if (current->left) s2.push(current->left);
            }

            // Process all nodes in s2
            while (!s2.empty()) {
                Node* current = s2.top();
                s2.pop();
                result.push_back(current->data);

                // Push children to s1 (left first for odd level)
                if (current->left) s1.push(current->left);
                if (current->right) s1.push(current->right);
            }
        }

        return result;
    }
};
