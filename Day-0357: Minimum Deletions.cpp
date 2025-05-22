// Minimum Deletions (MEDIUM)
// https://www.geeksforgeeks.org/problems/minimum-deletitions1648/1

class Solution {
public:
    int minDeletions(string s) {
        int n = s.size();
        vector<vector<int>> dp(n, vector<int>(n, 0));
        
        for (int i = 0; i < n; i++) dp[i][i] = 1;

        for (int len = 2; len <= n; len++) {
            for (int i = 0; i <= n - len; i++) {
                int j = i + len - 1;
                if (s[i] == s[j]) dp[i][j] = dp[i + 1][j - 1] + 2;
                else dp[i][j] = max(dp[i + 1][j], dp[i][j - 1]);
            }
        }

        int longestPalindromicSubseq = dp[0][n - 1];
        return n - longestPalindromicSubseq;
    }
};
