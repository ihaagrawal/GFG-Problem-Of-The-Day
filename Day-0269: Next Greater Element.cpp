// Next Greater Element (MEDIUM)
// https://www.geeksforgeeks.org/problems/next-larger-element-1587115620/1

class Solution {
  public:
    // Function to find the next greater element for each element of the array.
    vector<int> nextLargerElement(vector<int>& arr) {
        int n = arr.size();
        vector<int> result(n, -1);
        stack<int> s;
    
        for (int i = n - 1; i >= 0; i--) {
            while (!s.empty() && s.top() <= arr[i]) s.pop();
            if (!s.empty()) result[i] = s.top();
            s.push(arr[i]);
        }
    
        return result;
    }
};
