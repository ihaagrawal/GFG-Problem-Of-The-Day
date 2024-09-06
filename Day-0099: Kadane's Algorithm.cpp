// Kadane's Algorithm (MEDIUM)
// https://www.geeksforgeeks.org/problems/kadanes-algorithm-1587115620/1

class Solution {
  public:
    // Function to find the sum of contiguous subarray with maximum sum.
    long long maxSubarraySum(vector<int> &arr) {
        int n = arr.size(), max_sum = INT_MIN, sum = 0;
        int i = 0;
        
        while(i < n){
            sum += arr[i];
            max_sum = max(max_sum, sum);
            if(sum < 0) sum = 0;
            i++;
        }
        
        return max_sum;
    }
};
