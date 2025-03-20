// Stock Buy and Sell – Max 2 Transactions Allowed (HARD)
// https://www.geeksforgeeks.org/problems/buy-and-sell-a-share-at-most-twice/1

class Solution {
  public:
    int maxProfit(vector<int> &prices) {
        int n = prices.size();
            vector<vector<vector<int>>> dp(n+1, vector<vector<int>>(2, vector<int>(3, 0)));
    
            for(int i=n-1;i>=0;i--){
                for(int buy=0;buy<=1;buy++){
                    for(int cap=1;cap<=2;cap++){
                        if(buy){
                            int do_buy = -prices[i] + dp[i+1][0][cap];
                            int do_not_buy = 0 + dp[i+1][1][cap];
                            dp[i][buy][cap] = max(do_not_buy, do_buy);
                        }else{
                            int do_sell = prices[i] + dp[i+1][1][cap-1];
                            int do_not_sell = 0 + dp[i+1][0][cap];
                            dp[i][buy][cap] = max(do_not_sell, do_sell);
                        }
                    }
                }
            }
    
            return dp[0][1][2];
        
    }
};
