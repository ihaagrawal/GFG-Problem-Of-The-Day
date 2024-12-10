// Non-overlapping Intervals (MEDIUM)
// https://www.geeksforgeeks.org/problems/non-overlapping-intervals/1


class Solution {
  public:
    int minRemoval(vector<vector<int>> &intervals) {
        sort(intervals.begin(), intervals.end(), [](const vector<int> &a, const vector<int> &b) {
            return a[1] < b[1];
        });

        int count = 0;  
        int prevEnd = INT_MIN;  
    
        for (const auto &interval : intervals) {
            if (interval[0] < prevEnd) count++;
            else prevEnd = interval[1];
        }
        
        return count;
    }
};
