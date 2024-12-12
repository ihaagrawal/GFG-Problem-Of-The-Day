// Number of occurrence (EASY)
// https://www.geeksforgeeks.org/problems/number-of-occurrence2259/1


class Solution {
  public:
    int countFreq(vector<int>& nums, int target) {
        int n = nums.size();
        int first = -1, second = -1;
        int low = 0, high = n-1;

        while(low <= high){
            int mid = low + (high - low)/2;
            if(nums[mid] <= target){
                if(nums[mid] == target) second = mid;
                low = mid + 1;
            }else high = mid - 1;
        }

        low = 0, high = n-1;
        while(low <= high){
            int mid = low + (high - low)/2;
            if(nums[mid] >= target){
                if(nums[mid] == target) first = mid;
                high = mid -1;
            }else low = mid + 1;
        }

        if(first == -1 && second != -1) first = second;
        else if (second == -1 && first != -1) second = first;
        else if(second == -1 && first == -1) return 0;
        
        return second - first + 1;
    }
};
