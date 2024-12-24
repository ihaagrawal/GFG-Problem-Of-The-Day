// Search in a sorted Matrix (MEDIUM)
// https://www.geeksforgeeks.org/problems/search-in-a-matrix-1587115621/1


class Solution {
  public:
    // Function to search a given number in row-column sorted matrix.
    bool searchMatrix(vector<vector<int>> &matrix, int x) {
        int n = matrix.size(), m = matrix[0].size();
        int row = 0, col = m-1;
        while(row < n && col >= 0){
            if(matrix[row][col] == x) return 1;
            else if(matrix[row][col] > x) col--;
            else row++;
        }
        return 0;
    }
};
