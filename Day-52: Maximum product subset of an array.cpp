// Maximum product subset of an array (MEDIUM)
// https://www.geeksforgeeks.org/problems/maximum-product-subset-of-an-array/1


class Solution {
  public:
  
    long long int MOD = 1e9 + 7 ;
    long long int findMaxProduct(vector<int>& arr) {
        long long int pdt = 1;
        long long int neg = INT_MIN ;
        
        for(auto it : arr){
            if(it != 0)  pdt = (pdt*(it)%MOD)%MOD;
            if(it < 0) neg = max(neg,(long long int)it);
        }
        
        if(pdt < 0) pdt = pdt / neg ;
        return pdt ;
    }
};
