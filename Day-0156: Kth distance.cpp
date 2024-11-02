// Kth distance (EASY)
// https://www.geeksforgeeks.org/problems/kth-distance3757/1


class Solution {
  public:

    bool checkDuplicatesWithinK(vector<int>& arr, int k) {
        unordered_map<int, int> mp;
        for(int i=0;i<arr.size();i++){
            if(mp.find(arr[i]) != mp.end() && i - mp[arr[i]] <= k) return true;
            mp[arr[i]] = i;
        }
        return false;
    }
};
