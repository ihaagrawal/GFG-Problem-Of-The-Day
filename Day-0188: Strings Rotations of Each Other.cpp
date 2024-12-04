// Strings Rotations of Each Other (EASY)
// https://www.geeksforgeeks.org/problems/check-if-strings-are-rotations-of-each-other-or-not-1587115620/1

class Solution {
 public:
    bool areRotations(string &s1, string &s2) {
        if (s1.length() != s2.length()) return false;
        string concatenated = s1 + s1;
        return kmpSearch(concatenated, s2);
    }

private:
    bool kmpSearch(const string &text, const string &pattern) {
        int n = text.size(), m = pattern.size();
        vector<int> lps = computeLPS(pattern);
        int i = 0, j = 0;
        
        while (i < n) {
            if (text[i] == pattern[j]) {
                i++; j++;
                if (j == m) return true;
            } else if (j > 0) {
                j = lps[j - 1];
            } else {
                i++;
            }
        }
        return false;
    }

    vector<int> computeLPS(const string &pattern) {
        int m = pattern.size();
        vector<int> lps(m, 0);
        int len = 0, i = 1;

        while (i < m) {
            if (pattern[i] == pattern[len]) {
                lps[i++] = ++len;
            } else if (len > 0) {
                len = lps[len - 1];
            } else {
                lps[i++] = 0;
            }
        }
        return lps;
    }
};
