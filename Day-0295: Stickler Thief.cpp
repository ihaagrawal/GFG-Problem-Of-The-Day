// Stickler Thief (MEDIUM)
// https://www.geeksforgeeks.org/problems/stickler-theif-1587115621/1

class Solution {
  public:
    int findMaxSum(vector<int>& arr) {
        int n = arr.size();
        if(n == 0) return 0;
        if(n == 1) return arr[0];
        
        vector<int> dp(n, 0);
        dp[0] = arr[0];
        dp[1] = max(arr[0], arr[1]);
        
        for(int i=2;i<n;i++){
            dp[i] = max(dp[i-1], arr[i] + dp[i-2]);
        }
        
        return dp[n-1];
        
    }
};
