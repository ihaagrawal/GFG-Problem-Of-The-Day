// Min Chars to Add for Palindrome (HARD)
// https://www.geeksforgeeks.org/problems/minimum-characters-to-be-added-at-front-to-make-string-palindrome/1


class Solution {
  public:
    int minChar(string& s) {
        string rev = s;
        reverse(rev.begin(), rev.end());
        string t = s + "#" + rev;
        int n = t.size();
        
        vector<int> lps(n, 0);
        for (int i = 1; i < n; ++i) {
            int j = lps[i - 1];
            while (j > 0 && t[i] != t[j]) j = lps[j - 1];
            if (t[i] == t[j]) j++;
            lps[i] = j;
        }
        
        return s.size() - lps.back();
    }
};
