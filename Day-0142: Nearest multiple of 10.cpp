// Nearest multiple of 10 (EASY)
// https://www.geeksforgeeks.org/problems/nearest-multiple-of-102437/1

class Solution {
    private:
        void reverseString(string &s) {
            int start = 0;
            int end = s.size() - 1;
            while (start < end) {
                swap(s[start], s[end]);
                start++;
                end--;
            }
        }
    
    public:
        string roundToNearest(string numStr) {
            int length = numStr.size();
            int lastDigit = numStr[length - 1] - '0';
    
            if (lastDigit <= 5) {
                string result = "";
                for (int i = 0; i < length - 1; i++) {
                    result += numStr[i];
                }
                result += '0';
                return result;
            } else {
                string result = "";
                int carry = 1;
    
                for (int i = length - 2; i >= 0; i--) {
                    int digit = numStr[i] - '0' + carry;
                    int newDigit = digit % 10;
                    carry = digit / 10;
                    result += to_string(newDigit);
                }
                if (carry != 0) {
                    result += to_string(carry);
                }
                reverseString(result);
                return result + '0';
            }
        }

};
