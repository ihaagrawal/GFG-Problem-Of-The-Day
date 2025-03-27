// Minimum Platforms (MEDIUM)
// https://www.geeksforgeeks.org/problems/minimum-platforms-1587115620/1

class Solution {
  public:
    // Function to find the minimum number of platforms required at the
    // railway station such that no train waits.
    int findPlatform(vector<int>& arr, vector<int>& dep) {
        int n = arr.size();
        sort(arr.begin(), arr.end());
    	sort(dep.begin(), dep.end());
    	
    	int i=0, j=0, count=0, result=1;
    	while(i<n && j<n){
    	    if(arr[i] <= dep[j]){
    	        count++;
    	        i++;
    	    }else if(arr[i] > dep[j]){
    	        count--;
    	        j++;
    	    }
    	    
    	    result = max(result, count);
    	}
    	return result;
    }
};
