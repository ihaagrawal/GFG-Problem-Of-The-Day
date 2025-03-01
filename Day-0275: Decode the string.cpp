// Decode the string (MEDIUM)
// https://www.geeksforgeeks.org/problems/decode-the-string2444/1

class Solution {
  public:
    string decodedString(string &s) {
        stack<string> stringStack;
        stack<int> countStack;
        string currentString = "";
        int k = 0;
    
        for (char c : s) {
            if (isdigit(c)) {
                k = k * 10 + (c - '0');
            } else if (c == '[') {
                stringStack.push(currentString);
                countStack.push(k);
                currentString = "";
                k = 0;
            } else if (c == ']') {
                int repeatTimes = countStack.top();
                countStack.pop();
                string prevString = stringStack.top();
                stringStack.pop();
                string decodedPart = "";
                for (int i = 0; i < repeatTimes; ++i) {
                    decodedPart += currentString;
                }
                currentString = prevString + decodedPart;
            } else {
                currentString += c;
            }
        }
    
        return currentString;
    }
};
