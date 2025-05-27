// Print leaf nodes from preorder traversal of BST (MEDIUM)
// https://www.geeksforgeeks.org/problems/print-leaf-nodes-from-preorder-traversal-of-bst2657/1

class Solution {
    vector<int> leaves;
    void findLeaves(vector<int>& pre) {
        vector<int> left, right;
        int n = pre.size();
        for (int i = 1; i < n; i++) {
            if (pre[i] < pre[0]) left.push_back(pre[i]);
            else right.push_back(pre[i]);
        }
        if (left.empty() && right.empty()) {
            leaves.push_back(pre[0]);
            return;
        }
        if (!left.empty()) findLeaves(left);
        if (!right.empty()) findLeaves(right);
    }
  public:
    vector<int> leafNodes(vector<int>& pre) {
        findLeaves(pre);
        return leaves;
    }
};
