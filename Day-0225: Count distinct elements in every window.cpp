// Count distinct elements in every window (EASY)
// https://www.geeksforgeeks.org/problems/count-distinct-elements-in-every-window/1

class Solution {
  public:
    vector<int> countDistinct(vector<int> &arr, int k) {
        int n = arr.size();
        vector<int> result;
        
        unordered_map<int, int> mp;
        for(int i=0;i<k;i++) mp[arr[i]]++;
        result.push_back(mp.size());
        
        int left = 0, right = k;
        while(right < n){
            mp[arr[left]]--;
            if(mp[arr[left]] == 0) mp.erase(arr[left]);
            left++;
            mp[arr[right]]++;
            result.push_back(mp.size());
            right++;
        }
        
        return result;
    }
};
