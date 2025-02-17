// k largest elements (MEDIUM)
// https://www.geeksforgeeks.org/problems/k-largest-elements4206/1


class Solution {
  public:
    vector<int> kLargest(vector<int>& arr, int k) {
        priority_queue<int, vector<int>, greater<int>> minHeap;

        for (int num : arr) {
            minHeap.push(num);
            if (minHeap.size() > k) {
                minHeap.pop();
            }
        }
    
        vector<int> result;
        while (!minHeap.empty()) {
            result.push_back(minHeap.top());
            minHeap.pop();
        }
    
        reverse(result.begin(), result.end());
        return result;
    }
};
