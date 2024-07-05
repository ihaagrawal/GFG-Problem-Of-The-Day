// Vertical Width of a Binary Tree (MEDIUM)
// https://www.geeksforgeeks.org/problems/vertical-width-of-a-binary-tree/1


class Solution {
  public:
    // Function to find the vertical width of a Binary Tree.
    int verticalWidth(Node* root) {
        if (!root) return 0;

        unordered_set<int> st;
        queue<pair<Node*, int>> q;  
        q.push({root, 0});
    
        while (!q.empty()) {
            auto front = q.front();
            q.pop();
    
            Node* node = front.first;
            int s = front.second;
    
            st.insert(s);
    
            if (node->left) q.push({node->left, s - 1});
            if (node->right) q.push({node->right, s + 1});
        }
    
        return st.size();
    }
};
