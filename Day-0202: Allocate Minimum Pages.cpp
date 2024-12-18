// Allocate Minimum Pages (MEDIUM)
// https://www.geeksforgeeks.org/problems/allocate-minimum-number-of-pages0937/1


class Solution {
  public:
    bool isPossible(vector<int>& arr, int n, int k, int maxPages) {
        int studentsRequired = 1, currentSum = 0;
        for (int i = 0; i < n; ++i) {
            if (arr[i] > maxPages) return false;
            if (currentSum + arr[i] > maxPages) {
                studentsRequired++;
                currentSum = arr[i];
                if (studentsRequired > k) return false;
            } else {
                currentSum += arr[i];
            }
        }
        return true;
    }
    
    int findPages(vector<int>& arr, int k) {
        int n = arr.size();
        if (k > n) return -1;
        int low = *max_element(arr.begin(), arr.end());
        int high = accumulate(arr.begin(), arr.end(), 0);
        int result = -1;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (isPossible(arr, n, k, mid)) {
                result = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return result;
    }
};
