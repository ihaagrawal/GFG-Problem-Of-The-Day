// Reorganize The Array (EASY)
// https://www.geeksforgeeks.org/problems/reorganize-the-array4810/1


class Solution {
  public:
    vector<int> rearrange(const vector<int>& arr) {
        int n = arr.size();
        vector<int> result(n, -1);
        
        for(int i = 0; i < n; i++) {
            if(arr[i] >= 0 && arr[i] < n) {
                result[arr[i]] = arr[i];
            }
        }
        
        return result;
    }
};
