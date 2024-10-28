// Remove duplicates in array (EASY)
// https://www.geeksforgeeks.org/problems/remove-duplicates-in-small-prime-array/1


class Solution {
  public:
    vector<int> removeDuplicate(vector<int>& arr) {
        int n=arr.size();
        unordered_set<int> s1;
        vector<int> result;
        for(int i=0;i<n;i++){
             if (s1.find(arr[i]) == s1.end()) {
               s1.insert(arr[i]);
               result.push_back(arr[i]);
             }
        }
        return result;
    }
};
