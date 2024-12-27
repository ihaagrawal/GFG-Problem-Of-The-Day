// Count pairs with given sum (EASY)
// https://www.geeksforgeeks.org/problems/count-pairs-with-given-sum--150253/1


class Solution {
  public:
    int countPairs(vector<int> &arr, int target) {
        unordered_map<int, int> freq;
        int count = 0;
        for (int num : arr) {
            count += freq[target - num];
            freq[num]++;
        }
        return count;
    }
};