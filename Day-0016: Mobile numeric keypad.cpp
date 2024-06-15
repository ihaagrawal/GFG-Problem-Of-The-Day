// Mobile numeric keypad (MEDIUM)
// https://www.geeksforgeeks.org/problems/mobile-numeric-keypad5456/1

class Solution {
  public:
    long long getCount(int n) {
        vector<vector<long long>> dp(n + 1, vector<long long>(10, 0));
        
        // Define the neighbors for each key on the keypad
        vector<vector<int>> data = {
            {0, 8},         // Neighbors of 0
            {1, 2, 4},      // Neighbors of 1
            {1, 2, 3, 5},   // Neighbors of 2
            {2, 3, 6},      // Neighbors of 3
            {1, 4, 5, 7},   // Neighbors of 4
            {2, 4, 5, 6, 8},// Neighbors of 5
            {3, 5, 6, 9},   // Neighbors of 6
            {4, 7, 8},      // Neighbors of 7
            {5, 7, 8, 9, 0},// Neighbors of 8
            {6, 8, 9}       // Neighbors of 9
        };
        
        // Base case: there's one way to dial each digit with a length of 1
        for (int j = 0; j <= 9; ++j) {
            dp[1][j] = 1;
        }
        
        // Fill the DP table
        for (int i = 2; i <= n; ++i) {
            for (int j = 0; j <= 9; ++j) {
                for (int prev : data[j]) {
                    dp[i][j] += dp[i - 1][prev];
                }
            }
        }
        
        // Sum up the ways to dial a number of length n
        long long sum = 0;
        for (int j = 0; j <= 9; ++j) {
            sum += dp[n][j];
        }
        
        return sum;
    }
};
