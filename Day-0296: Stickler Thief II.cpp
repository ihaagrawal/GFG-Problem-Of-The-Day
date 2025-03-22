// Stickler Thief II (MEDIUM)
// https://www.geeksforgeeks.org/problems/house-robber-ii/1

class Solution {
  public:
    int maxValue(vector<int>& arr) {
        int n = arr.size();
        if (n == 1) return arr[0];
    
        auto robLinear = [&](int start, int end) -> int {
            int prev1 = 0, prev2 = 0;
            for (int i = start; i <= end; ++i) {
                int current = max(prev1, prev2 + arr[i]);
                prev2 = prev1;
                prev1 = current;
            }
            return prev1;
        };
    
        int case1 = robLinear(1, n - 1);
        int case2 = robLinear(0, n - 2);
    
        return max(case1, case2);
    }

};
