// Count Inversions (MEDIUM)
// https://www.geeksforgeeks.org/problems/inversion-of-array-1587115620/1

class Solution {
  public:
    // Function to count inversions in the array.
    int mergeAndCount(vector<int> &arr, int left, int mid, int right) {
        vector<int> temp;
        int i = left, j = mid + 1, inversions = 0;
    
        while (i <= mid && j <= right) {
            if (arr[i] <= arr[j]) {
                temp.push_back(arr[i++]);
            } else {
                temp.push_back(arr[j++]);
                inversions += (mid - i + 1); // Count inversions
            }
        }
    
        while (i <= mid) {
            temp.push_back(arr[i++]);
        }
    
        while (j <= right) {
            temp.push_back(arr[j++]);
        }
    
        for (int k = 0; k < temp.size(); ++k) {
            arr[left + k] = temp[k];
        }
    
        return inversions;
    }
    
    int mergeSortAndCount(vector<int> &arr, int left, int right) {
        if (left >= right) return 0;
    
        int mid = left + (right - left) / 2;
        int inversions = mergeSortAndCount(arr, left, mid);
        inversions += mergeSortAndCount(arr, mid + 1, right);
        inversions += mergeAndCount(arr, left, mid, right);
    
        return inversions;
    }
    
    int inversionCount(vector<int> &arr) {
        return mergeSortAndCount(arr, 0, arr.size() - 1);
    }
};
