// Longest Bounded-Difference Subarray (MEDIUM)
// https://www.geeksforgeeks.org/problems/longest-bounded-difference-subarray/1

class Solution {
  public:
    vector<int> longestSubarray(vector<int>& arr, int x) {
        int n = arr.size();
        int start = 0, end = 0, maxLength = 0, bestStart = 0;
        multiset<int> window;
        
        while (end < n) {
            window.insert(arr[end]);
            
            while (*window.rbegin() - *window.begin() > x) {
                window.erase(window.find(arr[start]));
                start++;
            }
            
            if (end - start + 1 > maxLength) {
                maxLength = end - start + 1;
                bestStart = start;
            }
            
            end++;
        }
        
        return vector<int>(arr.begin() + bestStart, arr.begin() + bestStart + maxLength);
        
    }
};
