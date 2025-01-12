// Trapping Rain Water (HARD)
// https://www.geeksforgeeks.org/problems/trapping-rain-water-1587115621/1


class Solution {
  public:
    int maxWater(vector<int> &nums) {
        int n = nums.size();
        long long left = 0, right = n-1;
        long long leftMax = 0, rightMax = 0;
        long long trapped = 0;
        
        while(left <= right){
            if(nums[left] <= nums[right]){
                if(nums[left] > leftMax) leftMax = nums[left];
                else trapped += leftMax - nums[left];
                left++;
            }else{
                if(nums[right] > rightMax) rightMax = nums[right];
                else trapped += rightMax - nums[right];
                right--;
            }
        }
        
        return trapped;
    }
};
