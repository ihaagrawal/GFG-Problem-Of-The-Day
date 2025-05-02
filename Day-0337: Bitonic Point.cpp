// Bitonic Point (EASY)
// https://www.geeksforgeeks.org/problems/maximum-value-in-a-bitonic-array3001/1

class Solution {
  public:
    int findMaximum(vector<int> &arr) {
        int left = 0, right = arr.size() - 1;

        while (left <= right) {
            int mid = left + (right - left) / 2;
            if ((mid == 0 || arr[mid] > arr[mid - 1]) && 
                (mid == arr.size() - 1 || arr[mid] > arr[mid + 1])) {
                return arr[mid];
            }
            if (mid > 0 && arr[mid - 1] > arr[mid]) {
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        return -1;
        
    }
};
