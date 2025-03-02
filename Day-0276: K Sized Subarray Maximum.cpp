// K Sized Subarray Maximum (MEDIUM)
// https://www.geeksforgeeks.org/problems/maximum-of-all-subarrays-of-size-k3101/1

class Solution {
  public:
    vector<int> maxOfSubarrays(vector<int>& arr, int k) {
        int maxi = 0, n = arr.size();
        vector<int> vec;
        for(int i=0;i<k;i++) maxi = max(maxi, arr[i]);
        
        vec.push_back(maxi);
        for(int i=k;i<n;i++){
            if(arr[i] < maxi and maxi == arr[i-k]){
                maxi = arr[i-k+1];
                for(int j=i-k+2;j<=i;j++){
                    if(arr[j] != maxi) maxi = max(maxi, arr[j]);
                }
            }else maxi = max(maxi, arr[i]);
            vec.push_back(maxi);
        }
        return vec;
        
    }
};
