// Longest Subarray with Majority Greater than K (MEDIUM)
// https://www.geeksforgeeks.org/problems/longest-subarray-with-majority-greater-than-k/1

class Solution {
  public:
    int longestSubarray(vector<int> &arr, int k) {
        int balance = 0, maxLength = 0;
        unordered_map<int, int> firstOccurrence;
    
        for (int i = 0; i < arr.size(); i++) {
            if (arr[i] <= k) balance--;
            else balance++;
    
            if (balance <= 0 && !firstOccurrence.count(balance)) firstOccurrence[balance] = i;
            if (balance <= 0 && firstOccurrence.count(balance - 1)) maxLength = max(maxLength, i - firstOccurrence[balance - 1]);
            if (balance > 0) maxLength = i + 1;
        }
    
        return maxLength;
        
    }
};
