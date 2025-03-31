// Maximize partitions in a String (EASY)
// https://www.geeksforgeeks.org/problems/maximize-partitions-in-a-string/1

class Solution {
  public:
    int maxPartitions(string &s) {
        unordered_map<char, int> lastIndex;
        int ans = 0, end = 0;
    
        for (int i = 0; i < s.size(); i++) {
            lastIndex[s[i]] = i;
        }
    
        for (int i = 0; i < s.size(); i++) {
            end = max(end, lastIndex[s[i]]);
            if (i == end) {
                ans++;
            }
        }
    
        return ans;
        
    }
};
