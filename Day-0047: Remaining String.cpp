// Remaining String (EASY)
// https://www.geeksforgeeks.org/problems/remaining-string3515/1


class Solution {
  public:

    string printString(string s, char ch, int count) {
        int n = s.length(), i = 0;

        for (i = 0; i < n; ++i) {
            if (s[i] == ch) {
                count--;
                if (count == 0) {
                    break;
                }
            }
        }

        if (count != 0) return "";
        return s.substr(i + 1);
    }
};
