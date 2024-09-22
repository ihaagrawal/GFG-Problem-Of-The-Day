// Longest Prefix Suffix (HARD)
// https://www.geeksforgeeks.org/problems/longest-prefix-suffix2527/1

class Solution {
  public:
    int lps(string str) {
        int n = str.length();
    
        // lps[i] will hold the length of the longest proper prefix
        // which is also a suffix for the substring str[0...i]
        vector<int> lps(n, 0);
        
        int length = 0; // length of the previous longest prefix-suffix
        int i = 1;
        
        while (i < n) {
            if (str[i] == str[length]) {
                length++;
                lps[i] = length;
                i++;
            } else {
                // mismatch after length matches
                if (length != 0) {
                    // move to the previous matching prefix-suffix length
                    length = lps[length - 1];
                } else {
                    lps[i] = 0; // no match, so lps[i] is 0
                    i++;
                }
            }
        }
        
        // Return the longest proper prefix-suffix for the entire string
        return lps[n - 1];
    }
};
