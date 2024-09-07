// Nth Natural Number (MEDIUM)
// https://www.geeksforgeeks.org/problems/nth-natural-number/1

class Solution {
  public:
    long long findNth(long long n) {
        string result = "";
        while(n > 0){
            result = to_string(n % 9) + result;
            n /= 9;
        }
        return stoll(result);
    }
};
