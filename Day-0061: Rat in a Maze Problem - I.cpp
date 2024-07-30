// Rat in a Maze Problem - I (MEDIUM)
// https://www.geeksforgeeks.org/problems/rat-in-a-maze-problem/1

class Solution {
  public:
  
    void check(vector<string>& result, vector<vector<int>>& mat, string str, int i, int j){
        int n = mat.size(), m = mat[0].size();
        if(i < 0 || j < 0 || i >= n || j >= m || mat[i][j] == -1 || mat[i][j] == 0) return;
        
        if(i == n-1 && j == m-1){
            result.push_back(str);
            return;
        }
        
        mat[i][j] = -1;
        
        check(result, mat, str+"D", i+1, j);
        check(result, mat, str+"U", i-1, j);
        check(result, mat, str+"R", i, j+1);
        check(result, mat, str+"L", i, j-1);
        
        mat[i][j] = 1;
        return;
    }
  
    vector<string> findPath(vector<vector<int>> &mat) {
        vector<string> result;
        check(result, mat, "", 0, 0);
        return result;
    }
};
