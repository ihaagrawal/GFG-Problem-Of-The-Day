// Longest Subarray with Sum K (MEDIUM)
// https://www.geeksforgeeks.org/problems/longest-sub-array-with-sum-k0809/1


class Solution {
  public:
    int longestSubarray(vector<int>& a, int k) {
        int n = a.size();
        unordered_map<int, int> mp;
        int sum = 0, length = 0;
        mp[0] = -1;
        
        for(int i=0;i<n;i++){
            sum += a[i];
            if(mp.find(sum-k) != mp.end()) length = max(length, i-mp[sum-k]);
            if(mp.find(sum) == mp.end()) mp[sum] = i;
        }
        return length;
    }
};
