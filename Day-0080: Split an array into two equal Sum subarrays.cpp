// Split an array into two equal Sum subarrays (EASY)
// https://www.geeksforgeeks.org/problems/split-an-array-into-two-equal-sum-subarrays/1

class Solution {
  public:
    bool canSplit(vector<int>& arr) {
        int sum = 0;
        for(int i : arr) sum += i;
        int split = 0;
        for(int i : arr){
            split += i;
            if(split == (sum - split)) return true;
        }
        
        return false;
    }
};
