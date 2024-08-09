// Maximize Array Value After Rearrangement (EASY)
// https://www.geeksforgeeks.org/problems/maximize-arrii-of-an-array0026/1

class Solution {
  public:
    long long MOD = 1e9 + 7;
    int Maximize(vector<int> arr) {
        int n = arr.size();
        sort(arr.begin(), arr.end());
        long long result = 0;
        for(int i=0;i<n;i++) result = (result % MOD + ((long long)arr[i] * i) % MOD) % MOD;
        return result;
    }
};
