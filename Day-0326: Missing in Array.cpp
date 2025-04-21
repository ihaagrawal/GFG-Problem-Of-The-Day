// Missing in Array (EASY)
// https://www.geeksforgeeks.org/problems/missing-number-in-array1416/1

class Solution {
  public:
    int missingNum(vector<int>& arr) {
        long long n = arr.size() + 1;
        long long totalSum = n * (n + 1) / 2;
        long long arraySum = 0;
        
        for (int num : arr) arraySum += num;
        
        return totalSum - arraySum;
    }
};
