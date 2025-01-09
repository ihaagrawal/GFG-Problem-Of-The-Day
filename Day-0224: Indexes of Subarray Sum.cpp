// Indexes of Subarray Sum (MEDIUM)
// https://www.geeksforgeeks.org/problems/subarray-with-given-sum-1587115621/1


class Solution {
  public:
    vector<int> subarraySum(vector<int> &arr, int s) {
        int n = arr.size();
        int left = 0;
        long long sum = 0;
        
        for(int right=0;right<n;right++){
            sum += arr[right];
            
            while(sum > s && left < right){
                sum -= arr[left];
                left++;
            }
            
            if(sum == s) return {left+1, right+1};
        }
        
        return {-1};
    }
};
