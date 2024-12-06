// Find H-Index (MEDIUM)
// https://www.geeksforgeeks.org/problems/find-h-index--165609/1


class Solution {
  public:
    // Function to find hIndex
    int hIndex(vector<int>& citations) {
        sort(citations.begin(), citations.end());
        int n = citations.size();
    
        for (int i = 0; i < n; ++i) {
            int h = n - i;
            if (citations[i] >= h) return h;
        }
    
        return 0;
    }
};
