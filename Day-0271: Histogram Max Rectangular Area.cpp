// Histogram Max Rectangular Area (HARD)
// https://www.geeksforgeeks.org/problems/maximum-rectangular-area-in-a-histogram-1587115620/1

class Solution {
  public:
    vector<int> findNse(const vector<int>& arr) {
        int n = arr.size();
        vector<int> nse(n, n);
        stack<int> st;
        
        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && arr[st.top()] >= arr[i]) st.pop();
            if (!st.empty()) nse[i] = st.top();
            st.push(i);
        }
        
        return nse;
    }
    
    vector<int> findPse(const vector<int>& arr) {
        int n = arr.size();
        vector<int> pse(n, -1);
        stack<int> st;
        
        for (int i = 0; i < n; i++) {
            while (!st.empty() && arr[st.top()] >= arr[i]) st.pop();
            if (!st.empty()) pse[i] = st.top();
            st.push(i);
        }
        
        return pse;
    }
    
    int getMaxArea(const vector<int>& arr) {
        int n = arr.size();
        vector<int> nse = findNse(arr);
        vector<int> pse = findPse(arr);
        
        long long max_area = 0;
        for (int i = 0; i < n; i++) {
            long long width = nse[i] - pse[i] - 1;
            long long area = static_cast<long long>(arr[i]) * width;
            max_area = max(max_area, area);
        }
        
        return max_area;
    }
}; 
