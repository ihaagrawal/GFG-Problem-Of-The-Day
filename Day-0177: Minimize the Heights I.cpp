// Minimize the Heights I (MEDIUM)
// https://www.geeksforgeeks.org/problems/minimize-the-heights-i/1


class Solution {
  public:
    int getMinDiff(int k, vector<int> &arr) {
        int n = arr.size();
        if (n == 1) return 0; 
    
        sort(arr.begin(), arr.end());
        int ans = arr[n - 1] - arr[0];
        int smallest = arr[0] + k;
        int largest = arr[n - 1] - k;
    
        for (int i = 0; i < n - 1; i++) {
            int minHeight = min(smallest, arr[i + 1] - k);
            int maxHeight = max(largest, arr[i] + k);
            ans = min(ans, maxHeight - minHeight);
        }
    
        return ans;
    }
};
