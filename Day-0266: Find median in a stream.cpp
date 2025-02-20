// Find median in a stream (HARD)
// https://www.geeksforgeeks.org/problems/find-median-in-a-stream-1587115620/1


class Solution {
  public:
    vector<double> getMedian(vector<int> &arr) {
        priority_queue<int> maxheap; 
        priority_queue<int, vector<int>, greater<int>> minheap; 
        vector<double> medians;
    
        for (int num : arr) {
            if (maxheap.empty() || num <= maxheap.top()) maxheap.push(num);
            else minheap.push(num);
    
            if (maxheap.size() > minheap.size() + 1) {
                minheap.push(maxheap.top());
                maxheap.pop();
            } else if (minheap.size() > maxheap.size()) {
                maxheap.push(minheap.top());
                minheap.pop();
            }
    
            if (maxheap.size() == minheap.size()) medians.push_back((maxheap.top() + minheap.top()) / 2.0);
            else medians.push_back(maxheap.top());
        }
    
        return medians;
    }
};
