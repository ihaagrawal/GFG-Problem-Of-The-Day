// Linked List Matrix (EASY)
// https://www.geeksforgeeks.org/problems/linked-list-matrix/1


class Solution {
  public:
    Node* constructLinkedMatrix(vector<vector<int>>& mat) {
        int n = mat.size();
        if (n == 0) return nullptr;
    
        vector<vector<Node*>> nodeMatrix(n, vector<Node*>(n, nullptr));
    
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                nodeMatrix[i][j] = new Node(mat[i][j]);
            }
        }
    
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (j < n - 1) {
                    nodeMatrix[i][j]->right = nodeMatrix[i][j + 1];
                }
                if (i < n - 1) {
                    nodeMatrix[i][j]->down = nodeMatrix[i + 1][j];
                }
            }
        }
    
        return nodeMatrix[0][0];
    }
};
