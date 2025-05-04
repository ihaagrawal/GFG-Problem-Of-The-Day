// Smallest distinct window (MEDIUM)
// https://www.geeksforgeeks.org/problems/smallest-distant-window3132/1

class Solution {
  public:
    int findSubString(string& str) {
        // code here
        unordered_set<char> distinctChars(str.begin(), str.end());
        int distinctCount = distinctChars.size();
        unordered_map<char, int> charCount;
    
        int start = 0, minLength = INT_MAX;
        int matchedCount = 0;
    
        for (int end = 0; end < str.size(); ++end) {
            char endChar = str[end];
            charCount[endChar]++;
            if (charCount[endChar] == 1) {
                matchedCount++;
            }
    
            while (matchedCount == distinctCount) {
                minLength = min(minLength, end - start + 1);
                char startChar = str[start];
                charCount[startChar]--;
                if (charCount[startChar] == 0) {
                    matchedCount--;
                }
                start++;
            }
        }
    
        return minLength;
    }
};
