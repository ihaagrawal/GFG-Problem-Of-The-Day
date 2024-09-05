// Missing in Array (EASY)
// https://www.geeksforgeeks.org/problems/missing-number-in-array1416/1

class Solution {
  public:

    // Note that the size of the array is n-1
    int missingNumber(int n, vector<int>& arr) {
        int total = accumulate(arr.begin(), arr.end(), 0);
        int sum = n * (n+1)/2;
        
        return (sum - total);
    }
};
