// Split array in three equal sum subarrays (MEDIUM)
// https://www.geeksforgeeks.org/problems/split-array-in-three-equal-sum-subarrays/1


class Solution {
  public:
    // Function to determine if array arr can be split into three equal sum sets.
    vector<int> findSplit(vector<int>& arr) {
        int count = 0, sum = 0, n = arr.size();
        int i = 0, j = -1;
        
        int total = accumulate(arr.begin(), arr.end(), 0);
        if(total % 3 != 0) return {-1, -1};
        if(total == 0) return {0, 0};
        
        int x = total / 3;
        for(int k=0;k<n;k++){
            sum += arr[k];
            if(sum == x){
                sum = 0;
                count++;
                if(j == -1) j = k;
            }
        }
        
        if(count == 3) return {i, j};
        return {-1, -1};
    }
};
