// Longest Consecutive Subsequence (MEDIUM)
// https://www.geeksforgeeks.org/problems/longest-consecutive-subsequence2449/1


class Solution {
  public:

    // Function to return length of longest subsequence of consecutive integers.
    int longestConsecutive(vector<int>& arr) {
        int n = arr.size();
        sort(arr.begin(), arr.end());
        int i=0, j=1, max_len = 1, len = 1;
        
        while(j < n){
            if(arr[j] == arr[i] + 1) len++;
            else if(arr[j] == arr[i]){
                i++;
                j++;
                max_len = max(max_len, len);
                continue;
            }
            else if(arr[j] != arr[i] + 1){
                max_len = max(max_len, len);
                len = 1;
            }
            max_len = max(max_len, len);
            i++;
            j++;
        }
        
        return max_len;
    }
};
