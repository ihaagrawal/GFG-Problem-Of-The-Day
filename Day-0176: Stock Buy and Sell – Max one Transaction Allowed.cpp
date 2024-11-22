// Stock Buy and Sell – Max one Transaction Allowed (EASY)
// https://www.geeksforgeeks.org/problems/buy-stock-2/1


class Solution {
  public:
    int maximumProfit(vector<int> &prices) {
        int n = prices.size(), mini = prices[0], profit = 0;
        for(int i=0;i<n;i++){
            if(mini > prices[i]) mini = prices[i];
            int val = prices[i] - mini;
            if(val > profit) profit = val;
        }
        return profit;
    }
};
