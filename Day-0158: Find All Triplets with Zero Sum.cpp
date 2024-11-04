// Find All Triplets with Zero Sum (EASY)
// https://www.geeksforgeeks.org/problems/find-all-triplets-with-zero-sum/1


class Solution {
  public:
    vector<vector<int>> findTriplets(vector<int> &arr) {
        int n = arr.size();
        
        unordered_map<int, vector<int>> mp ;
        for(int i=0;i<n;i++) mp[arr[i]].push_back(i) ;
        
        vector<vector<int>> ans;
        
        for(int i=1;i<n;i++){
            for(int j=i+1;j<n;j++){
                int sum = -1 * (arr[i] + arr[j]) ;
                for(int k : mp[sum]){
                    if(k < i) ans.push_back({k , i , j}) ;
                }
            }
        }
        
        return ans;
    }
};
