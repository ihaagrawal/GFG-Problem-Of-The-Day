// Missing And Repeating (MEDIUM)
// https://www.geeksforgeeks.org/problems/find-missing-and-repeating2512/1


class Solution {
  public:
    vector<int> findTwoElement(vector<int>& arr) {
        int n = arr.size();
        vector<int> count(n+1, 0);
        int repeating = -1, missing = -1;
        
        for(int i = 0; i < n; i++) count[arr[i]]++;
        for(int i = 1; i <= n; i++) {
            if(count[i] == 0) missing = i;
            else if(count[i] > 1) repeating = i;
        }
        
        return {repeating, missing};
    }
};
