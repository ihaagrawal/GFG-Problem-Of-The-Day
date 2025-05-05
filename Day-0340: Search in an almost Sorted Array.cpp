// Search in an almost Sorted Array (MEDIUM)
// https://www.geeksforgeeks.org/problems/search-in-an-almost-sorted-array/1

class Solution {
  public:
    int findTarget(vector<int>& arr, int target) {
        int low = 0, high = arr.size() - 1;
        while (low <= high) {
            int mid = low + (high - low) / 2;
    
            if (arr[mid] == target) return mid;
            if (mid > 0 && arr[mid - 1] == target) return mid - 1;
            if (mid < arr.size() - 1 && arr[mid + 1] == target) return mid + 1;
    
            if (arr[mid] > target) high = mid - 2;
            else low = mid + 2;
        }
        return -1;
        
    }
};
