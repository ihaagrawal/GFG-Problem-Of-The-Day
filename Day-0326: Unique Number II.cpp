// Unique Number II (MEDIUM)
// https://www.geeksforgeeks.org/problems/finding-the-numbers0215/1?timeMachineDate=2025-04-23

class Solution {
  public:
    vector<int> singleNum(vector<int>& arr) {
        int xorResult = 0;
        for (int num : arr) {
            xorResult ^= num;
        }
    
        int rightmostSetBit = xorResult & -xorResult;
        int num1 = 0, num2 = 0;
    
        for (int num : arr) {
            if (num & rightmostSetBit) {
                num1 ^= num;
            } else {
                num2 ^= num;
            }
        }
    
        vector<int> result = {num1, num2};
        sort(result.begin(), result.end());
        return result;
    }
};
