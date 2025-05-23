// Total Decoding Messages (MEDIUM)
// https://www.geeksforgeeks.org/problems/total-decoding-messages1235/1

class Solution {
  public:
    int countWays(string &digits) {
        int n = digits.length();
        if (n == 0 || digits[0] == '0') return 0;
        
        vector<int> dp(n + 1, 0);
        dp[0] = 1;
        dp[1] = 1;
        
        for (int i = 2; i <= n; ++i) {
            if (digits[i - 1] != '0') {
                dp[i] += dp[i - 1];
            }
            int twoDigit = stoi(digits.substr(i - 2, 2));
            if (twoDigit >= 10 && twoDigit <= 26) {
                dp[i] += dp[i - 2];
            }
        }
        
        return dp[n];
    }
};
