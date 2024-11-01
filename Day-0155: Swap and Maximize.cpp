// Swap and Maximize (EASY)
// https://www.geeksforgeeks.org/problems/swap-and-maximize5859/1


class Solution {
  public:
    long long maxSum(vector<int>& arr) {
        long long sum = 0;
        sort(arr.begin(), arr.end());
        
        int n = arr.size(), i = 0, j = n-1;
        while(i <= j){
            sum += abs(arr[i] - arr[j]);
            sum += abs(arr[i] - arr[j]);
            i++;
            j--;
        }
        
        return sum;
    }
};
