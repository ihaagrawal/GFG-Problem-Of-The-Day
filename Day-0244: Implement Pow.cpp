// Implement Pow (MEDIUM)
// https://www.geeksforgeeks.org/problems/powx-n/1


class Solution {
  public:
    double power(double b, int e) {
        double result = 1.0;
        bool isNegative = e < 0;
        e = abs(e);
    
        while (e > 0) {
            if (e % 2 == 1) result *= b;
            b *= b;
            e /= 2;
        }
    
        return isNegative ? 1.0 / result : result;
    }
};
