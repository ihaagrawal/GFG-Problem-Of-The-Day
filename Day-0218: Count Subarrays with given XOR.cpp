// Count Subarrays with given XOR (MEDIUM)
// https://www.geeksforgeeks.org/problems/count-subarray-with-given-xor/1


class Solution {
  public:
    long subarrayXor(vector<int> &arr, int k) {
        unordered_map<int, int> freq;
        int xorSum = 0;
        long count = 0;
    
        for (int num : arr) {
            xorSum ^= num;
            if (xorSum == k) count++;
            if (freq.find(xorSum ^ k) != freq.end()) count += freq[xorSum ^ k];
            freq[xorSum]++;
        }
    
        return count;
    }
};
