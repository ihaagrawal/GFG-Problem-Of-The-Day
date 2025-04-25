// Majority Element (MEDIUM)
// https://www.geeksforgeeks.org/problems/majority-element-1587115620/1

class Solution {
  public:
    int majorityElement(vector<int>& arr) {
        int n = arr.size();
        int maj = n/2;
        unordered_map<int, int> mp;
        
        for(int i=0;i<n;i++) mp[arr[i]]++;
        
        for(auto it : mp){
            if(it.second > maj) return it.first;
        }
        
        return -1;
        
    }
};
