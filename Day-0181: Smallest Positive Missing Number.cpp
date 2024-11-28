// Smallest Positive Missing Number (MEDIUM)
// https://www.geeksforgeeks.org/problems/smallest-positive-missing-number-1587115621/1?timeMachineDate=2024-11-27

class Solution {
  public:
    // Function to find the smallest positive number missing from the array.
    int missingNumber(vector<int> &arr) {
        int n = arr.size();
        bool containsOne = false;
        for(int i=0;i<n;i++){
            if(arr[i] == 1) containsOne = true;
            else if(arr[i] <= 0 || arr[i] > n) arr[i] = 1;
        }
        
        if(!containsOne) return 1;
        
        for(int i=0;i<n;i++){
            int num = abs(arr[i]);
            int index = num-1;
            if(arr[index] > 0) arr[index] *= -1;
        }
        
        for(int i=0;i<n;i++){
            if(arr[i] > 0) return i+1;
        }
        
        return n+1;
    }
};
