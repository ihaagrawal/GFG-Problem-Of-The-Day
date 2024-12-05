// Sort 0s, 1s and 2s (EASY)
// https://www.geeksforgeeks.org/problems/sort-an-array-of-0s-1s-and-2s4231/1


class Solution {
  public:
    void sort012(vector<int>& arr) {
        int n = arr.size();
        int l = -1, r = n, i = 0;
        
        while(i < r && l < r){
            if(arr[i] == 0){
                l++;
                swap(arr[i], arr[l]);
                i++;
            }else if(arr[i] == 2){
                r--;
                swap(arr[i], arr[r]);
            }else i++;
        }
    }
};
