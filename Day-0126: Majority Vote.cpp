// Majority Vote (MEDIUM)
// https://www.geeksforgeeks.org/problems/majority-vote/1

class Solution {
  public:
    // Function to find the majority elements in the array
    vector<int> findMajority(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return {-1};
    
        int candidate1 = -1, candidate2 = -1, count1 = 0, count2 = 0;
    
        for (int num : nums) {
            if (num == candidate1) {
                count1++;
            } else if (num == candidate2) {
                count2++;
            } else if (count1 == 0) {
                candidate1 = num;
                count1 = 1;
            } else if (count2 == 0) {
                candidate2 = num;
                count2 = 1;
            } else {
                count1--;
                count2--;
            }
        }
    
        count1 = count2 = 0;
        for (int num : nums) {
            if (num == candidate1) count1++;
            else if (num == candidate2) count2++;
        }
    
        vector<int> result;
        if (count1 > n / 3) result.push_back(candidate1);
        if (count2 > n / 3) result.push_back(candidate2);
    
        if (result.empty()) return {-1};
        sort(result.begin(), result.end());
        return result;
    }
};
