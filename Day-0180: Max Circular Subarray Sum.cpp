// Max Circular Subarray Sum (HARD)
// https://www.geeksforgeeks.org/problems/max-circular-subarray-sum-1587115620/1

class Solution {
  public:
    // arr: input array
    // Function to find maximum circular subarray sum.
    int circularSubarraySum(vector<int> &arr) {
        int n = arr.size();
        int maxSum = INT_MIN, curMax = 0;
        for (int i = 0; i < n; ++i) {
            curMax = max(arr[i], curMax + arr[i]);
            maxSum = max(maxSum, curMax);
        }
    
        int totalSum = 0, minSum = INT_MAX, curMin = 0;
        for (int i = 0; i < n; ++i) {
            totalSum += arr[i];
            curMin = min(arr[i], curMin + arr[i]);
            minSum = min(minSum, curMin);
        }
    
        if (maxSum < 0) return maxSum;
        return max(maxSum, totalSum - minSum);
    }
};
