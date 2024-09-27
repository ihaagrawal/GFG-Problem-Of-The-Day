// K Sized Subarray Maximum (MEDIUM)
// https://www.geeksforgeeks.org/problems/maximum-of-all-subarrays-of-size-k3101/1

class Solution {
  public:
    // Function to find maximum of each subarray of size k.
    vector<int> max_of_subarrays(int windowSize, vector<int> &array) {
        int arraySize = array.size();
        if(windowSize > arraySize) return {};
    
        priority_queue<pair<int,int>> maxHeap;
        int startIndex = 1;
        vector<int> result;
    
        for(int i = 0; i < windowSize; i++) {
            maxHeap.push({array[i], i});
        }
        result.push_back(maxHeap.top().first);
    
        for(int i = windowSize; i < arraySize; i++) {
            maxHeap.push({array[i], i});
            
            while(!maxHeap.empty() && maxHeap.top().second < startIndex) {
                maxHeap.pop();
            }
            result.push_back(maxHeap.top().first);
            startIndex++;
        }
        
        return result;
    }

};
