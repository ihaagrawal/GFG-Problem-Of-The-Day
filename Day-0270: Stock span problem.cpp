// Stock span problem (MEDIUM)
// https://www.geeksforgeeks.org/problems/stock-span-problem-1587115621/1

class Solution {
  public:
    vector<int> calculateSpan(vector<int>& arr) {
        int n = arr.size();
        vector<int> span(n, 1);
        stack<int> st;
    
        for (int i = 0; i < n; ++i) {
            while (!st.empty() && arr[st.top()] <= arr[i]) st.pop();
            span[i] = st.empty() ? (i + 1) : (i - st.top());
            st.push(i);
        }
    
        return span;
    }
};
