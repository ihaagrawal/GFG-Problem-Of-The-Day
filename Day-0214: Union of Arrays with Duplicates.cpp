// Union of Arrays with Duplicates (EASY)
// https://www.geeksforgeeks.org/problems/union-of-two-arrays3538/1


class Solution {
  public:
    // Function to return the count of number of elements in union of two arrays.
    int findUnion(vector<int>& a, vector<int>& b) {
        int n = a.size(), m = b.size();
        set<int> st;
        
        for(int i=0;i<n;i++) st.insert(a[i]);
        for(int i=0;i<m;i++) st.insert(b[i]);
        
        return st.size();
    }
};
