// Boolean Parenthesization (HARD)
// https://www.geeksforgeeks.org/problems/boolean-parenthesization5610/1

class Solution {
public:
    int countWays(string &s) {
        int n = s.size();
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(n, vector<int>(2, -1)));
        return count(s, 0, n - 1, 1, dp); 
    }

private:
    int count(string &s, int i, int j, int isTrue, vector<vector<vector<int>>> &dp) {
        if (i > j) return 0;

        if (i == j) {
            return (isTrue == 1) ? (s[i] == 'T') : (s[i] == 'F');
        }

        if (dp[i][j][isTrue] != -1) return dp[i][j][isTrue];

        int ways = 0;
        for (int k = i + 1; k < j; k += 2) {
            char op = s[k];
            int lt = count(s, i, k - 1, 1, dp);  
            int lf = count(s, i, k - 1, 0, dp);  
            int rt = count(s, k + 1, j, 1, dp);  
            int rf = count(s, k + 1, j, 0, dp); 

            if (op == '&') {
                ways += (isTrue == 1) ? (lt * rt) : (lt * rf + lf * rt + lf * rf);
            } else if (op == '|') {
                ways += (isTrue == 1) ? (lt * rt + lt * rf + lf * rt) : (lf * rf);
            } else if (op == '^') {
                ways += (isTrue == 1) ? (lt * rf + lf * rt) : (lt * rt + lf * rf);
            }
        }

        dp[i][j][isTrue] = ways;
        return ways;
    }
};
