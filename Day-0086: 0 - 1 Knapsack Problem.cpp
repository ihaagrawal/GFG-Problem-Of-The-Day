// 0 - 1 Knapsack Problem (MEDIUM)
// https://www.geeksforgeeks.org/problems/0-1-knapsack-problem0945/1


class Solution {
  public:
    int findMaxValue(int capacity, vector<int>& weights, vector<int>& values, int currentIndex, vector<vector<int>>& memo) {
    
        if (currentIndex >= weights.size())return 0;
        if (memo[capacity][currentIndex] != -1) return memo[capacity][currentIndex];
    
        int maxValue = 0;
        if (capacity - weights[currentIndex] >= 0)
            maxValue = max(maxValue, values[currentIndex] + findMaxValue(capacity - weights[currentIndex], weights, values, currentIndex + 1, memo));
    
        maxValue = max(maxValue, findMaxValue(capacity, weights, values, currentIndex + 1, memo));
        return memo[capacity][currentIndex] = maxValue;
    }
    
    int knapSack(int maxWeight, vector<int>& weights, vector<int>& values) {
        int numItems = weights.size();
        vector<vector<int>> memo(maxWeight + 1, vector<int>(numItems, -1));
        return findMaxValue(maxWeight, weights, values, 0, memo);
    }

};
