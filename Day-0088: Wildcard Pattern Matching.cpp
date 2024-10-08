// Wildcard Pattern Matching (HARD)
// https://www.geeksforgeeks.org/problems/wildcard-pattern-matching/1

class Solution {
  public:
    /*You are required to complete this method*/
    int wildCard(string pattern, string str) {
        int n = pattern.size(), m = str.size();
        vector<vector<int>> dp(n+2, vector<int>(m+2, 0));
        dp[n][m] = 1;
        
        for(int i=n;i>=0;i--){
            for(int j=m;j>=0;j--){
                if(pattern[i] == str[j] || pattern[i] == '?'){
                    dp[i][j] = dp[i][j] | dp[i+1][j+1];
                }
                if(pattern[i] == '*'){
                    dp[i][j] = dp[i][j] | dp[i+1][j+1];
                    dp[i][j] = dp[i][j] | dp[i][j+1];
                    dp[i][j] = dp[i][j] | dp[i+1][j];
                }
            }
        }
        
        return dp[0][0];
    }
};
