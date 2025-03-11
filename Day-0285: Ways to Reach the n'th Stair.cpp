// Ways to Reach the n'th Stair (MEDIUM)
// https://www.geeksforgeeks.org/problems/count-ways-to-reach-the-nth-stair-1587115620/1

class Solution {
  public:
    int countWays(int n) {
        if (n == 0 || n == 1) return 1; 
        int prev2 = 1, prev1 = 1, current;
    
        for (int i = 2; i <= n; ++i) {
            current = prev1 + prev2; 
            prev2 = prev1;          
            prev1 = current;        
        }
    
        return prev1;
    }
};
