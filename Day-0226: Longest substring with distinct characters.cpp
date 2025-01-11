// Longest substring with distinct characters (EASY)
// https://www.geeksforgeeks.org/problems/longest-distinct-characters-in-string5848/1


class Solution {
  public:
    int longestUniqueSubstr(string &s) {
        int n = s.length(), max_count = 0;
        map<char, int> mp;  
        int start = 0;     
    
        for (int end = 0; end < n; end++) {
            if (mp.find(s[end]) != mp.end()) {
                start = max(start, mp[s[end]] + 1);
            }
            mp[s[end]] = end;
            max_count = max(max_count, end - start + 1);
        }
    
        return max_count;
    }
};
