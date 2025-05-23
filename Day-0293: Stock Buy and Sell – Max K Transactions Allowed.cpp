// Stock Buy and Sell – Max K Transactions Allowed (HARD)
// https://www.geeksforgeeks.org/problems/maximum-profit4657/1

class Solution {
  public:
    int maxProfit(vector<int>& prices, int k) {
        int n = prices.size();
        if (n == 0 || k == 0) return 0;
    
        if (k >= n / 2) {
            int maxProfit = 0;
            for (int i = 1; i < n; ++i) {
                if (prices[i] > prices[i - 1])
                    maxProfit += prices[i] - prices[i - 1];
            }
            return maxProfit;
        }
    
        vector<vector<int>> dp(k + 1, vector<int>(n, 0));
    
        for (int i = 1; i <= k; ++i) {
            int max_diff = -prices[0];
            for (int j = 1; j < n; ++j) {
                dp[i][j] = max(dp[i][j - 1], prices[j] + max_diff);
                max_diff = max(max_diff, dp[i - 1][j] - prices[j]);
            }
        }
    
        return dp[k][n - 1];
        
    }
};
