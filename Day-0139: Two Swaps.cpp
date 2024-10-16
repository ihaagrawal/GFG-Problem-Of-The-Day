// Two Swaps (EASY)
// https://www.geeksforgeeks.org/problems/two-swaps--155623/1


class Solution {
  public:
    bool checkSorted(vector<int> &arr) {
        int n = arr.size();
        int count = 0;
        
        for(int i=0;i<n;i++){
            while(arr[i] != arr[arr[i] - 1]){
                swap(arr[i], arr[arr[i] - 1]);
                count++;
            }
        }
        
        return count == 2 || count == 0;
    }
};
