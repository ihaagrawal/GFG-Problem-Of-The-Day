// Pythagorean Triplet (MEDIUM)
// https://www.geeksforgeeks.org/problems/pythagorean-triplet3018/1

class Solution {
  public:
    bool pythagoreanTriplet(vector<int>& nums) {
        unordered_set<long long> squaredValues;
        
        for (int num : nums) squaredValues.insert(1LL * num * num);
        
        int size = nums.size();
        
        for (int i = 0; i < size; i++) {
            for (int j = i + 1; j < size; j++) {
                long long sumOfSquares = 1LL * nums[i] * nums[i] + 1LL * nums[j] * nums[j];
                if (squaredValues.find(sumOfSquares) != squaredValues.end()) return true;
            }
        }
        return false;
    }
};
