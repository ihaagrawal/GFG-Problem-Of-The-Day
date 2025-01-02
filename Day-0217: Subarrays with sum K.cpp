// Subarrays with sum K (MEDIUM)
// https://www.geeksforgeeks.org/problems/subarrays-with-sum-k/1


class Solution {
  public:
    int countSubarrays(vector<int> &arr, int k) {
        unordered_map<int, int> prefixSumCount;
        int currentSum = 0, count = 0;

        prefixSumCount[0] = 1; 

        for (int num : arr) {
            currentSum += num;

            if (prefixSumCount.find(currentSum - k) != prefixSumCount.end()) {
                count += prefixSumCount[currentSum - k];
            }

            prefixSumCount[currentSum]++;
        }

        return count;
    }
};
