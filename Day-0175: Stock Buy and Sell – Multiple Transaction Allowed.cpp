// Stock Buy and Sell – Multiple Transaction Allowed (HARD)
// https://www.geeksforgeeks.org/problems/stock-buy-and-sell2615/1


class Solution {
  public:
    int maximumProfit(vector<int> &prices) {
        int n = prices.size(), result = 0;
        if(n < 2) return 0;
        for(int i=0;i<n-1;i++){
            if(prices[i] < prices[i+1]) result += prices[i+1] - prices[i];
        }
        return result;
    }
};
