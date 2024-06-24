// Summed Matrix (EASY)
// https://www.geeksforgeeks.org/problems/summed-matrix5834/1

class Solution {
  public:
    long long sumMatrix(long long n, long long q) {
        if(q>(n+n)) return 0;
        if(q<n) return q-1;
        
        long long num = 1+n;
        long long diff = abs(num-q);
        return abs(n-diff);
    }
};
