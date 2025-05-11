// K-th Largest Sum Contiguous Subarray (MEDIUM)
// https://www.geeksforgeeks.org/problems/k-th-largest-sum-contiguous-subarray/1

class Solution {
  public:
    int kthLargest(vector<int> &arr, int k) {
        std::priority_queue<int, std::vector<int>, std::greater<int>> minHeap;

        int n = arr.size();
    
        for (int start = 0; start < n; ++start) {
            int sum = 0;
    
            for (int end = start; end < n; ++end) {
                sum += arr[end]; 
                minHeap.push(sum);
                if (minHeap.size() > k) minHeap.pop();
            }
        }
    
        return minHeap.top();
        
    }
};
