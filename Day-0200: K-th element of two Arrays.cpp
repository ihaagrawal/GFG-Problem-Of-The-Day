// K-th element of two Arrays (MEDIUM)
// https://www.geeksforgeeks.org/problems/k-th-element-of-two-sorted-array1317/1


class Solution {
  public:
    int kthElement(vector<int>& arr1, vector<int>& arr2, int k) {
        vector<int> result;
        result.insert(result.end(), arr1.begin(), arr1.end());
        result.insert(result.end(), arr2.begin(), arr2.end());
        sort(result.begin(), result.end());
        return result[k-1];
    }
};
