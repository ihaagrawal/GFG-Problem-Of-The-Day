// nCr (MEDIUM)
// https://www.geeksforgeeks.org/problems/ncr1019/1

class Solution {
  public:
    int nCr(int n, int r) {
        if (r > n) return 0;
        if (r == 0 || r == n) return 1;
    
        if (r > n - r) r = n - r; 
        
        long long result = 1;
        for (int i = 0; i < r; ++i) result = result * (n - i) / (i + 1);
        return result;
        
    }
};
