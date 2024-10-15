// Subarray range with given sum (MEDIUM)
// https://www.geeksforgeeks.org/problems/subarray-range-with-given-sum0128/1


class Solution {
  public:
    // Function to count the number of subarrays which adds to the given sum.
    int subArraySum(vector<int>& arr, int tar) {
        map<int, int> mp;
        int n = arr.size();
        int count = 0, sum = 0;
        
        for(int i=0;i<n;i++){
            sum += arr[i];
            if(sum == tar) count++;
            
            if(mp.find(sum - tar) != mp.end()) count += mp[sum - tar];
            mp[sum]++;
        }
        
        return count;
    }
};
