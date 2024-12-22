// Search in a Row-Column sorted matrix (EASY)
// https://www.geeksforgeeks.org/problems/search-in-a-matrix17201720/1


class Solution {
  public:
    bool matSearch(vector<vector<int>> &mat, int x) {
        int rows = mat.size();
        int cols = mat[0].size();
    
        int row = 0, col = cols - 1;
        while (row < rows && col >= 0) {
            if (mat[row][col] == x) {
                return true;
            } else if (mat[row][col] > x) {
                col--;
            } else {
                row++;
            }
        }
        return false;
    }
};
