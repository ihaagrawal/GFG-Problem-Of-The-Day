// Padovan Sequence (EASY)
// https://www.geeksforgeeks.org/problems/padovan-sequence2855/1

class Solution {
  public:
    int padovanSequence(int n) {
        int a=1, b=1, c=1;
        int mod = 1e9 + 7;
        
        for(int i=3;i<=n;i++){
            int d = (a+b) % mod;
            a=b;
            b=c;
            c=d;
        }
        
        return c;
    }
};
