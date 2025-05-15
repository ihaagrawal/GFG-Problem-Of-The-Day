// Substrings with same first and last characters (EASY)
// https://www.geeksforgeeks.org/problems/substrings-with-similar-first-and-last-characters3644/1

class Solution {
  public:
    int countSubstring(string &s) {
        unordered_map<char, int> freqMap;
        int n = s.size();
        int count = 0;
    
        for (char c : s) freqMap[c]++;
    
        for (auto &entry : freqMap) {
            int freq = entry.second;
            count += (freq * (freq + 1)) / 2;
        }
    
        return count;
        
    }
};
