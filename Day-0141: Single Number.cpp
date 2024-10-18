// Single Number (EASY)
// https://www.geeksforgeeks.org/problems/single-number1014/1

class Solution {
  public:
    int getSingle(vector<int>& arr) {
        int n = arr.size();
        map<int, int> mp;
        for(int i=0;i<n;i++) mp[arr[i]]++;
        for(auto it : mp){
            if(it.second % 2 != 0) return it.first;
        }
        return -1;
    }
};
