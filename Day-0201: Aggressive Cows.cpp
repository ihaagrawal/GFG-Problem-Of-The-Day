// Aggressive Cows (MEDIUM)
// https://www.geeksforgeeks.org/problems/aggressive-cows/1


class Solution {
  public:

    bool canPlaceCows(vector<int> &stalls, int k, int dist) {
        int cowsPlaced = 1;
        int lastPos = stalls[0];
        
        for (int i = 1; i < stalls.size(); i++) {
            if (stalls[i] - lastPos >= dist) {
                cowsPlaced++;
                lastPos = stalls[i];
                if (cowsPlaced == k) return true;
            }
        }
        return false;
    }
    
    int aggressiveCows(vector<int> &stalls, int k) {
        sort(stalls.begin(), stalls.end());
        int low = 1, high = stalls.back() - stalls[0], ans = 0;
        
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (canPlaceCows(stalls, k, mid)) {
                ans = mid;
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        return ans;
    }
};
