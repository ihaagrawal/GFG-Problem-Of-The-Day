// Make array elements unique (MEDIUM)
// https://www.geeksforgeeks.org/problems/make-array-elements-unique--170645/1


class Solution {
  public:
    int minIncrements(vector<int>& arr) {
        int n = arr.size();
        long long count = 0;
        sort(arr.begin(), arr.end());
        
        for(int i=1;i<n;i++){
            if(arr[i] <= arr[i-1]){
                int val = arr[i-1] - arr[i] + 1;
                count += val;
                arr[i] += val;
            }
        }
        
        return count;
    }
};
