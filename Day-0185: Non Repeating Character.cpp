// Non Repeating Character (EASY)
// https://www.geeksforgeeks.org/problems/non-repeating-character-1587115620/1


class Solution {
  public:
    char nonRepeatingChar(string &s) {
        vector<int> freq(26, 0);
        for (char c : s) freq[c - 'a']++;
        for (char c : s) {
            if (freq[c - 'a'] == 1) return c;
        }
        return '$';
    }
};
