// Longest alternating subsequence (MEDIUM)
// https://www.geeksforgeeks.org/problems/longest-alternating-subsequence5951/1


class Solution {
  public:
    int alternatingMaxLength(vector<int>& arr) {
        int n = arr.size();
        if (n == 0) return 0;
        if (n == 1) return 1;

        int maxlen = 1, inc = 1, dec = 1;

        for (int i = 1; i < n; ++i) {
            if (arr[i] > arr[i - 1]) inc = dec + 1;
            else if (arr[i] < arr[i - 1]) dec = inc + 1;
            maxlen = max(maxlen, max(inc, dec));
        }

        return maxlen;
    }
};
