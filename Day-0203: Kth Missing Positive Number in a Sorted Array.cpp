// Kth Missing Positive Number in a Sorted Array (MEDIUM)
// https://www.geeksforgeeks.org/problems/kth-missing-positive-number-in-a-sorted-array/1


class Solution {
  public:
    int kthMissing(vector<int> &arr, int k) {
        int missingCount = 0, current = 1, index = 0;

        while (true) {
            if (index < arr.size() && arr[index] == current) index++;
            else {
                missingCount++;
                if (missingCount == k) return current;
            }
            current++;
        }
    }
};
