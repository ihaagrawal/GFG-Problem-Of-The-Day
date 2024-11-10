// Union of Two Sorted Arrays with Distinct Elements (EASY)
// https://www.geeksforgeeks.org/problems/union-of-two-sorted-arrays-with-distinct-elements/1


class Solution {
  public:
    // a,b : the arrays
    // Function to return a list containing the union of the two arrays.
    vector<int> findUnion(vector<int> &a, vector<int> &b) {
        vector<int> result;
        int i = 0, j = 0;
        
        while (i < a.size() && j < b.size()) {
            if (a[i] < b[j]) {
                if (result.empty() || result.back() != a[i]) result.push_back(a[i]);
                i++;
            } else if (a[i] > b[j]) {
                if (result.empty() || result.back() != b[j]) result.push_back(b[j]);
                j++;
            } else {
                if (result.empty() || result.back() != a[i]) result.push_back(a[i]);
                i++;
                j++;
            }
        }
        
        while (i < a.size()) {
            if (result.empty() || result.back() != a[i]) result.push_back(a[i]);
            i++;
        }
        
        while (j < b.size()) {
            if (result.empty() || result.back() != b[j]) result.push_back(b[j]);
            j++;
        }
        
        return result;
    }
};
