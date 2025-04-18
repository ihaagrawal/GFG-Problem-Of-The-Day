// Subset Sum Problem (MEDIUM)
// https://www.geeksforgeeks.org/problems/subset-sum-problem-1611555638/1

class Solution {
  public:
    bool isSubsetSum(vector<int>& arr, int target) {
        int n = arr.size();
        vector<vector<bool>> dp(n+1, vector<bool>(target+1, false));
    
        for(int i=0;i<=n;i++) dp[i][0] = true;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=target;j++){
                if(arr[i-1] > j) dp[i][j] = dp[i-1][j];
                else dp[i][j] = dp[i-1][j] || dp[i-1][j - arr[i-1]];
            }
        }
        
        return dp[n][target];
        
    }
};
