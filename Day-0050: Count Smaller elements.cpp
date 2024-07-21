// Count Smaller elements (HARD)
// https://www.geeksforgeeks.org/problems/count-smaller-elements2214/1


class Solution {
  public:
    void merge(vector<int>& count, int left, int mid, int right, vector<int>& result, vector<int>& arr) {
        vector<int> temp(right - left + 1);
        int i = left, j = mid + 1, k = 0;

        while (i <= mid && j <= right) {
            if (arr[count[i]] <= arr[count[j]]) {
                temp[k] = count[j];
                j++;
            } else {
                result[count[i]] += right - j + 1;
                temp[k] = count[i];
                i++;
            }
            k++;
        }

        while (i <= mid) temp[k++] = count[i++];
        while (j <= right) temp[k++] = count[j++];
        for (int i = left; i <= right; i++) count[i] = temp[i - left];
    }

    void mergesort(vector<int>& count, int left, int right, vector<int>& result, vector<int>& arr) {
        if (left < right) {
            int mid = left + (right - left) / 2;
            mergesort(count, left, mid, result, arr);
            mergesort(count, mid + 1, right, result, arr);
            merge(count, left, mid, right, result, arr);
        }
    }

    vector<int> constructLowerArray(vector<int> &arr) {
        int n = arr.size();
        vector<int> result(n, 0), count(n);
        for (int i = 0; i < n; i++) count[i] = i;
        mergesort(count, 0, n - 1, result, arr);
        return result;
    }
};
