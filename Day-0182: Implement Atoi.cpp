// Implement Atoi (MEDIUM)
// https://www.geeksforgeeks.org/problems/implement-atoi/1

class Solution {
  public:
    int myAtoi(char *s) {
        int n = strlen(s), i = 0;
    
        while (i < n && s[i] == ' ') i++;
        
        int sign = 1;
        if (i < n && (s[i] == '-' || s[i] == '+')) {
            sign = (s[i] == '-') ? -1 : 1;
            i++;
        }
        
        int result = 0;
        while (i < n && s[i] >= '0' && s[i] <= '9') {
            int num = s[i] - '0';
            
            if (result > (INT_MAX - num) / 10) {
                return (sign == 1) ? INT_MAX : INT_MIN;
            }
            
            result = result * 10 + num;
            i++;
        }
        
        return sign * result;
    }
};
