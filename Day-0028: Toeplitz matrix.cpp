// Toeplitz matrix (MEDIUM)
// https://www.geeksforgeeks.org/problems/toeplitz-matrix/1

bool isToepliz(vector<vector<int>>& mat) {
    int n = mat.size(), m = mat[0].size();
    
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(i+1 < n && j+1 < m){
                if(mat[i][j] != mat[i+1][j+1]) return false;
            }
        }
    }
    
    return true;
}
