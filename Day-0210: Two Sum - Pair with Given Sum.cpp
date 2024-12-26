// Two Sum - Pair with Given Sum (EASY)
// https://www.geeksforgeeks.org/problems/key-pair5616/1


class Solution {
  public:
    bool twoSum(vector<int>& arr, int x) {
        int n = arr.size();
        map<int,int> mp;
	    
	    for(int i=0;i<n;i++){
	        int diff = x - arr[i];
	        if(mp.find(diff) != mp.end()) return true;
	        else mp[arr[i]]++;
	    }
	    
	    return false;
    }
};
