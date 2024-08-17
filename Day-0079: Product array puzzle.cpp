// Product array puzzle (EASY)
// https://www.geeksforgeeks.org/problems/product-array-puzzle4525/1


class Solution {
  public:
    // nums: given vector
    // return the Product vector P that hold product except self at each index
    vector<long long int> productExceptSelf(vector<long long int>& nums) {
        int n = nums.size();
        vector<long long> result(n, 0);
        
        for(int i=0;i<n;i++){
            long long pdt = 1;
            for(int j=0;j<n;j++){
                if(i != j) pdt *= nums[j];
            }
            
            result[i] = pdt;
        }
        
        return result;
       
    }
};
