// Sum of all substrings of a number (MEDIUM)
// https://www.geeksforgeeks.org/problems/sum-of-all-substrings-of-a-number-1587115621/1

class Solution {
public:
    int sumSubstrings(string &s) {
        int n = s.size();
        long long totalSum = 0, currentSum = 0;

        for (int i = 0; i < n; ++i) {
            currentSum = currentSum * 10 + (s[i] - '0') * (i + 1);
            totalSum += currentSum;
        }

        return totalSum; // Ensure the total fits within 32-bit signed integer
    }
};
