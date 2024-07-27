// Form a palindrome (MEDIUM)
// https://www.geeksforgeeks.org/problems/form-a-palindrome1455/1


class Solution{
  public:
    int countMin(string str){
        int n = str.length();
        vector<vector<int>> dp(n, vector<int>(n, 0));
        
        for (int i = 1; i < n; ++i) {
            for (int k = 0; k < n - i; ++k) {
                int j = k + i;
                if (str[k] == str[j]) dp[k][j] = dp[k + 1][j - 1];
                else dp[k][j] = min(dp[k][j - 1], dp[k + 1][j]) + 1;
            }
        }
        
        return dp[0][n - 1];
    }
};
