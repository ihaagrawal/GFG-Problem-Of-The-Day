// Left Rotate Matrix K times (MEDIUM)
// https://www.geeksforgeeks.org/problems/left-rotate-matrix-k-times2351/1

class Solution {
  public:
    vector<vector<int>> rotateMatrix(int k, vector<vector<int>> mat) {
        int n=mat.size();
        int m=mat[0].size();
        k=k%(m);
        
        for (auto &row : mat) {
            reverse(row.begin(), row.end());
            reverse(row.rbegin(), row.rbegin() + k);
            reverse(row.rbegin() + k, row.rend());
        }
        return mat;
    }
};
