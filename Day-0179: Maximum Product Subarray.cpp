// Maximum Product Subarray (MEDIUM)
// https://www.geeksforgeeks.org/problems/maximum-product-subarray3604/1


class Solution {
  public:
    // Function to find maximum product subarray
    int maxProduct(vector<int> &arr) {
        int n = arr.size();
        long long maxp = INT_MIN;
	    
	    for(int i=0;i<n;i++){
	        long long pdt = 1;
	        for(int j=i;j<n;j++){
	            pdt *= arr[j];
	            maxp = max(maxp, pdt);
	        }
	    }
	    
	    return maxp;
    }
};
