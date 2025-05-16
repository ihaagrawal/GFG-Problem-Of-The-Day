// Smallest range in K lists (HARD)
// https://www.geeksforgeeks.org/problems/find-smallest-range-containing-elements-from-k-lists/1

class Solution {
  public:
    vector<int> findSmallestRange(vector<vector<int>>& arr) {
        int k = arr.size();
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<>> pq;

        int mx = INT_MIN, start = 0, end = INT_MAX;

        for (int i = 0; i < k; i++) {
            pq.push({arr[i][0], {i, 0}});
            mx = max(mx, arr[i][0]);
        }

        while (!pq.empty()) {
            pair<int, pair<int, int>> top = pq.top();
            pq.pop();
            int mn = top.first;
            int row = top.second.first;
            int col = top.second.second;

            if (mx - mn < end - start) {
                start = mn;
                end = mx;
            }

            if (col + 1 == arr[row].size()) break;

            int nextValue = arr[row][col + 1];
            pq.push({nextValue, {row, col + 1}});
            mx = max(mx, nextValue);
        }

        return {start, end};
        
    }
};
