// Sorted and Rotated Minimum (EASY)
// https://www.geeksforgeeks.org/problems/minimum-element-in-a-sorted-and-rotated-array3611/1


class Solution {
  public:
    int findMin(vector<int>& nums) {
        int n = nums.size();
        int left = 0, right = n-1;
        int smallest = INT_MAX;
        
        while(left <= right){
            int mid = (left + right)/2;
            if(nums[right] <= nums[mid]){
                smallest = min(smallest, nums[right]);
                left = mid + 1;
            }else{
                smallest = min(smallest, nums[mid]);
                right = mid - 1;
            }
        }
        
        return smallest;
    }
};
