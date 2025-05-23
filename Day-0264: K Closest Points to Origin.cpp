// K Closest Points to Origin (MEDIUM)
// https://www.geeksforgeeks.org/problems/k-closest-points-to-origin--172242/1


class Solution {
  public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pair<int, vector<int>>> maxHeap;

        for (auto& point : points) {
            int x = point[0], y = point[1];
            int distance = x * x + y * y;
            maxHeap.push({distance, point});
    
            if (maxHeap.size() > k) maxHeap.pop();
        }
    
        vector<vector<int>> result;
        while (!maxHeap.empty()) {
            result.push_back(maxHeap.top().second);
            maxHeap.pop();
        }
    
        return result;
    }
};
