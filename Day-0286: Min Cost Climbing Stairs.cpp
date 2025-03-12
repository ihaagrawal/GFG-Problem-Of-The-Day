// Min Cost Climbing Stairs (MEDIUM)
// https://www.geeksforgeeks.org/problems/min-cost-climbing-stairs/1

class Solution {
  public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        int prev2 = cost[0], prev1 = cost[1];
        if(n <= 2) return min(prev1, prev2);
        
        for(int i=2;i<n;i++){
            int current = min(prev1, prev2) + cost[i];
            prev2 = prev1;
            prev1 = current;
        }
        
        return min(prev1, prev2);
    }
};
