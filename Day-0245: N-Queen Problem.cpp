// N-Queen Problem (HARD)
// https://www.geeksforgeeks.org/problems/n-queen-problem0315/1

class Solution {
  public:
    bool canPlace(int row, int col, vector<int>& board) {
        for (int i = 0; i < col; i++) {
            if (board[i] == row || 
                board[i] - i == row - col || 
                board[i] + i == row + col) {
                return false;
            }
        }
        return true;
    }

    void solve(int col, vector<int>& board, vector<vector<int>>& result, int n) {
        if (col == n) {
            vector<int> solution;
            for (int i = 0; i < n; i++) {
                solution.push_back(board[i] + 1);
            }
            result.push_back(solution);
            return;
        }
        
        for (int row = 0; row < n; row++) {
            if (canPlace(row, col, board)) {
                board[col] = row;
                solve(col + 1, board, result, n);
                board[col] = -1;  
            }
        }
    }

    vector<vector<int>> nQueen(int n) {
        vector<vector<int>> result;
        vector<int> board(n, -1);  
        solve(0, board, result, n);
        return result;
    }
};
