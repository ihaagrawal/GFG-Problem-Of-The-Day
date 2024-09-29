// Total count (EASY)
// https://www.geeksforgeeks.org/problems/total-count2415/1


class Solution {
  public:
    int totalCount(int k, vector<int>& arr) {
        int count = 0;
        for(int i=0;i<arr.size();i++){
            count++;
            while(arr[i]>k){
                arr[i]-=k;
                count++;
            }
        }
        return count;
    }
};
