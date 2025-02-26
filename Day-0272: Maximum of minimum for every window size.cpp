// Maximum of minimum for every window size (HARD)
// https://www.geeksforgeeks.org/problems/maximum-of-minimum-for-every-window-size3453/1


class Solution {
  public:
    vector<int> maxOfMins(vector<int>& arr) {
        int n = arr.size();
        vector<int> prevSmaller(n, -1), nextSmaller(n, n);
        stack<int> s;
    
        for (int i = 0; i < n; ++i) {
            while (!s.empty() && arr[s.top()] >= arr[i]) s.pop();
            if (!s.empty()) prevSmaller[i] = s.top();
            s.push(i);
        }
    
        while (!s.empty()) s.pop();
    
        for (int i = n - 1; i >= 0; --i) {
            while (!s.empty() && arr[s.top()] >= arr[i]) s.pop();
            if (!s.empty()) nextSmaller[i] = s.top();
            s.push(i);
        }
    
        vector<int> result(n + 1, 0);
    
        for (int i = 0; i < n; ++i) {
            int length = nextSmaller[i] - prevSmaller[i] - 1;
            result[length] = max(result[length], arr[i]);
        }
    
        for (int i = n - 1; i >= 1; --i) result[i] = max(result[i], result[i + 1]);
        result.erase(result.begin());
        return result;
    }
};
