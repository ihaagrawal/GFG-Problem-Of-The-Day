// Find rectangle with corners as 1 (MEDIUM)
// https://www.geeksforgeeks.org/problems/find-rectangle-with-corners-as-1--141631/1

class Solution {
  public:
    bool ValidCorner(vector<vector<int> >& mat) {
        int n = mat.size(), m = mat[0].size();
        bool f = false;
        
        for(int i=0;i<m-1;i++){
            for(int j=i+1;j<m;j++){
                f = false;
                for(int k=0;k<n;k++){
                    if(mat[k][j] && mat[k][i]){
                        if(f) return true;
                        f = true;
                    }
                }
            }
        }
        
        return false;
    }
};
