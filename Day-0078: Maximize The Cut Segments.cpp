// Maximize The Cut Segments (MEDIUM)
// https://www.geeksforgeeks.org/problems/cutted-segments1642/1


class Solution
{
    public:
    
    int solve(int n, int x, int y, int z, vector<int>& dp){
        if(n < 0) return INT_MIN;
        if(n == 0) return 0;
        if(dp[n] != -1) return dp[n];
        
        int line1 = solve(n-x, x, y, z, dp);
        int line2 = solve(n-y, x, y, z, dp);
        int line3 = solve(n-z, x, y, z, dp);
        
        return dp[n] = 1 + max({line1, line2, line3});
    }
    
    int maximizeTheCuts(int n, int x, int y, int z){
        vector<int> dp(n+1, -1);
        int result = solve(n, x, y, z, dp);
        return max(result, 0);
    }
};
