// K Sum Paths (MEDIUM)
// https://www.geeksforgeeks.org/problems/k-sum-paths/1

/*
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
    public:
        int sumK(Node *root, int k) {
            unordered_map<int, int> prefix;
            prefix[0] = 1;
            return dfs(root, k, 0, prefix);
        }

    private:
        int dfs(Node *node, int k, int sum, unordered_map<int, int> &prefix) {
            if (!node) return 0;
    
            sum += node->data;
    
            int cnt = prefix[sum - k];
    
            prefix[sum]++;
    
            cnt += dfs(node->left, k, sum, prefix);
            cnt += dfs(node->right, k, sum, prefix);
    
            prefix[sum]--;
    
            return cnt;
        }
};
