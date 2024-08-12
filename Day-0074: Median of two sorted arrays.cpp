// Median of two sorted arrays (MEDIUM)
// https://www.geeksforgeeks.org/problems/sum-of-middle-elements-of-two-sorted-arrays2305/1

class Solution {
  public:
    int SumofMiddleElements(vector<int> &arr1, vector<int> &arr2) {
        int n = arr1.size(), m = arr2.size();
        vector<int> arr;
        for(int i=0;i<n;i++) arr.push_back(arr1[i]);
        for(int i=0;i<m;i++) arr.push_back(arr2[i]);
        sort(arr.begin(), arr.end());
        
        int i = arr.size() / 2;
        if(arr.size() % 2 == 1) return arr[i];
        return arr[i] + arr[i-1];
    }
};
