// Pascal Triangle (MEDIUM)
// https://www.geeksforgeeks.org/problems/pascal-triangle0652/1

class Solution {
  public:
    vector<int> nthRowOfPascalTriangle(int n) {
        vector<int> row(n);
        row[0] = 1; 
        
        for (int k = 1; k < n; ++k) {
            row[k] = (long long)row[k - 1] * (n - k) / k;
        }
        
        return row; 
        
    }
};
