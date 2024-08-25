// Number of pairs (MEDIUM)
// https://www.geeksforgeeks.org/problems/number-of-pairs-1587115620/1


class Solution {
  public:
    long long countPairs(vector<int> &A, vector<int> &B) {
        vector<double> a(A.size()), b(B.size());
    
        for(int i = 0; i < A.size(); i++) a[i] = (double)log(A[i]) / (double)A[i];
        for(int j = 0; j < B.size(); j++) b[j] = (double)log(B[j]) / (double)B[j];
        
        sort(a.begin(), a.end(), greater<double>());
        sort(b.begin(), b.end(), greater<double>());
        
        int i = 0, j = 0, n = a.size(), m = b.size();
        long long cnt = 0;
        
        while(i < n && j < m) {
            if(a[i] > b[j]){
                cnt += (m - j);
                i++;
            } else j++;
        }
        
        return cnt;
    }
};
