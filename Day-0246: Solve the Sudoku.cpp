// Solve the Sudoku (HARD)
// https://www.geeksforgeeks.org/problems/solve-the-sudoku-1587115621/1


class Solution {
  public:
    public:
    void solveSudoku(vector<vector<int>> &mat) {
        solve(mat);
    }

private:
    bool solve(vector<vector<int>> &mat) {
        for (int row = 0; row < 9; row++) {
            for (int col = 0; col < 9; col++) {
                if (mat[row][col] == 0) {
                    for (int num = 1; num <= 9; num++) {
                        if (isValid(mat, row, col, num)) {
                            mat[row][col] = num;

                            if (solve(mat)) {
                                return true;
                            }

                            mat[row][col] = 0; // Backtrack
                        }
                    }
                    return false; // No valid number found
                }
            }
        }
        return true; // All cells filled
    }

    bool isValid(vector<vector<int>> &mat, int row, int col, int num) {
        // Check row
        for (int x = 0; x < 9; x++) {
            if (mat[row][x] == num) {
                return false;
            }
        }

        // Check column
        for (int x = 0; x < 9; x++) {
            if (mat[x][col] == num) {
                return false;
            }
        }

        // Check 3x3 sub-box
        int startRow = (row / 3) * 3;
        int startCol = (col / 3) * 3;
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                if (mat[startRow + i][startCol + j] == num) {
                    return false;
                }
            }
        }

        return true;
    }
};
