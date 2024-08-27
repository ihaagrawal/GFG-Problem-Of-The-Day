// Maximum Difference (MEDIUM)
// https://www.geeksforgeeks.org/problems/maximum-difference-1587115620/1

class Solution {
  public:
    /*You are required to complete this method */
    int findMaxDiff(vector<int> &arr) {
        int n = arr.size();
        vector<int> left(n, 0), right(n, 0);
        
        for(int i=0;i<n;i++){
            if(i == 0) left[i] = 0;
            for(int j=i;j>=0;j--){
                if(arr[i] > arr[j]){
                    left[i] = arr[j];
                    break;
                }
            }
        }
        
        for(int i=n-1;i>=0;i--){
            if(i == n-1) right[i] = 0;
            for(int j=i+1;j<n;j++){
                if(arr[i] > arr[j]){
                    right[i] = arr[j];
                    break;
                }
            }
        }
        
        int max_diff = 0;
        for(int i=0;i<n;i++){
            max_diff = max(max_diff, abs(left[i] - right[i]));
        }
        
        return max_diff;
    }
};
