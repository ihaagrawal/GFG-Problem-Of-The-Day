// Largest Pair Sum (EASY)
// https://www.geeksforgeeks.org/problems/pair-sum--120604/1

class Solution {
  public:
    int pairsum(vector<int> &arr) {
        int n = arr.size();
        sort(arr.begin(), arr.end());
        return arr[n-1] + arr[n-2];
    }
};
