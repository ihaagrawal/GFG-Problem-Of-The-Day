// Move All Zeroes to End (EASY)
// https://www.geeksforgeeks.org/problems/move-all-zeroes-to-end-of-array0751/1

class Solution {
  public:
    void pushZerosToEnd(vector<int>& arr) {
        int i = 0, j = 0;
        int n = arr.size();
        
        while(j < n){
            if(arr[j] != 0){
                arr[i] = arr[j];
                i++;
            }
            j++;
        }
        
        while(i < n) arr[i++] = 0;
    }
};
