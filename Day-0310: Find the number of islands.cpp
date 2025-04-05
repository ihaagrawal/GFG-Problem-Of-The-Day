// Find the number of islands (MEDIUM)
// https://www.geeksforgeeks.org/problems/find-the-number-of-islands/1

class Solution {
  public:
    void dfs(vector<vector<char>>& grid, int i, int j, int n, int m) {
        if (i < 0 || i >= n || j < 0 || j >= m || grid[i][j] == 'W') {
            return;
        }

        grid[i][j] = 'W';

        vector<int> dirX = {-1, -1, -1, 0, 0, 1, 1, 1};
        vector<int> dirY = {-1, 0, 1, -1, 1, -1, 0, 1};

        for (int d = 0; d < 8; ++d) {
            dfs(grid, i + dirX[d], j + dirY[d], n, m);
        }
    }

    int countIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        if (n == 0) return 0;
        int m = grid[0].size();
        int count = 0;

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (grid[i][j] == 'L') {
                    ++count;
                    dfs(grid, i, j, n, m);
                }
            }
        }
        return count;
    }
};
