// Palindrome SubStrings (MEDIUM)
// https://www.geeksforgeeks.org/problems/count-palindrome-sub-strings-of-a-string0652/1


class Solution {
public:
    int countPS(string &s) {
        int n = s.size(), count = 0;
        if (n < 2) return 0;

        for (int i = 0; i < n; i++) {
            count += countPalindromesFromCenter(s, i, i);
            count += countPalindromesFromCenter(s, i, i + 1);
        }

        return count;
    }

private:
    int countPalindromesFromCenter(const string &s, int left, int right) {
        int count = 0;
        while (left >= 0 && right < s.size() && s[left] == s[right]) {
            if (right - left + 1 >= 2) count++;
            left--;
            right++;
        }
        return count;
    }
};
