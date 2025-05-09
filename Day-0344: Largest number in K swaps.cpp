// Largest number in K swaps (MEDIUM)
// https://www.geeksforgeeks.org/problems/largest-number-in-k-swaps-1587115620/1

class Solution {
  public:
    // Function to find the largest number after k swaps.
    void findLargest(string& s, int k, string& maxNum, int index) {
        if (k == 0)
            return;

        char maxDigit = s[index];
        for (int i = index + 1; i < s.size(); ++i) {
            if (s[i] > maxDigit)
                maxDigit = s[i];
        }

        if (maxDigit != s[index]) 
            --k;

        for (int i = index; i < s.size(); ++i) {
            if (s[i] == maxDigit) {
                swap(s[index], s[i]);
                if (s > maxNum) 
                    maxNum = s;

                findLargest(s, k, maxNum, index + 1);
                swap(s[index], s[i]);  // Backtrack
            }
        }
    }

    string findMaximumNum(string& s, int k) {
        string maxNum = s;
        findLargest(s, k, maxNum, 0);
        return maxNum;
    }
};
