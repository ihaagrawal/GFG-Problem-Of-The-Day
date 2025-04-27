// Multiply two strings (MEDIUM)
// https://www.geeksforgeeks.org/problems/multiply-two-strings/1

class Solution {
  public:
    /*You are required to complete below function */
    string multiplyStrings(string& s1, string& s2) {
        // Your code here
        auto removeLeadingZeros = [](string& s) {
        while (s.length() > 1 && s[0] == '0') {
            s.erase(s.begin());
            }
        };
    
        removeLeadingZeros(s1);
        removeLeadingZeros(s2);
    
        bool isNegative = false;
        if (s1[0] == '-') {
            isNegative = !isNegative;
            s1 = s1.substr(1);
        }
        if (s2[0] == '-') {
            isNegative = !isNegative;
            s2 = s2.substr(1);
        }
    
        if (s1 == "0" || s2 == "0") {
            return "0";
        }
    
        int m = s1.length(), n = s2.length();
        string result(m + n, '0');
    
        reverse(s1.begin(), s1.end());
        reverse(s2.begin(), s2.end());
    
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                int mul = (s1[i] - '0') * (s2[j] - '0') + (result[i + j] - '0');
                result[i + j] = (mul % 10) + '0';
                result[i + j + 1] += (mul / 10);
            }
        }
    
        reverse(result.begin(), result.end());
        removeLeadingZeros(result);
    
        if (isNegative) {
            result = "-" + result;
        }
    
        return result;
    }
};
