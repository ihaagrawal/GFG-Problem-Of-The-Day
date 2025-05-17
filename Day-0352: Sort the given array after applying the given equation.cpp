// Sort the given array after applying the given equation (MEDIUM)
// https://www.geeksforgeeks.org/problems/sort-the-given-array-after-applying-the-given-equation0304/1

class Solution {
  public:
    int transform(int x, int A, int B, int C) {
        return A * x * x + B * x + C;
    }
    
    vector<int> sortArray(vector<int> &arr, int A, int B, int C) {
        int n = arr.size();
        vector<int> result(n);
        int i = 0, j = n - 1; 
        int index = (A > 0) ? n - 1 : 0; 
    
        while (i <= j) {
            int start = transform(arr[i], A, B, C);
            int end = transform(arr[j], A, B, C);
            
            if (A > 0) { 
                if (start > end) {
                    result[index--] = start;
                    i++;
                } else {
                    result[index--] = end;
                    j--;
                }
            } else {
                if (start < end) {
                    result[index++] = start;
                    i++;
                } else {
                    result[index++] = end;
                    j--;
                }
            }
        }
        return result;
    }
};
