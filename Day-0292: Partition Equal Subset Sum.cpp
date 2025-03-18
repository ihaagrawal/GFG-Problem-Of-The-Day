// Partition Equal Subset Sum (MEDIUM)
// https://www.geeksforgeeks.org/problems/subset-sum-problem2014/1

class Solution {
  public:
    bool equalPartition(vector<int>& arr) {
        int n = arr.size();
        int totalSum = accumulate(arr.begin(), arr.end(), 0);
    
        if (totalSum % 2 != 0) return false;
    
        int target = totalSum / 2;
        vector<bool> dp(target + 1, false);
        dp[0] = true;
    
        for (int num : arr) {
            for (int j = target; j >= num; --j) {
                dp[j] = dp[j] || dp[j - num];
            }
        }
    
        return dp[target];
    }
};
