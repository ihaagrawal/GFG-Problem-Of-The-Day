// Longest valid Parentheses (HARD)
// https://www.geeksforgeeks.org/problems/longest-valid-parentheses5657/1


class Solution {
  public:
    int maxLength(string& str) {
        int maxValidLength = 0, openCount = 0, closeCount = 0;

    for (int i = 0; i < str.length(); i++) {
        if (str[i] == '(') openCount++;
        else closeCount++;
    
        if (closeCount > openCount) openCount = closeCount = 0;
        if (closeCount == openCount) maxValidLength = max(maxValidLength, closeCount * 2);
    }
    
    openCount = closeCount = 0;
    
    for (int i = str.length() - 1; i >= 0; i--) {
        if (str[i] == '(') openCount++;
        else closeCount++;
    
        if (closeCount < openCount) openCount = closeCount = 0;
        if (closeCount == openCount) maxValidLength = max(maxValidLength, closeCount * 2);
    }
    
    return maxValidLength;

    }
};
