// Spirally traversing a matrix (MEDIUM)
// https://www.geeksforgeeks.org/problems/spirally-traversing-a-matrix-1587115621/1

class Solution {
  public:
    vector<int> spirallyTraverse(vector<vector<int> > &matrix) {
        int n = matrix.size(), m = matrix[0].size();
        int left = 0, right = m-1, top = 0, bottom = n-1;
        vector<int> result;
        
        while(left <= right && top <= bottom){
            for(int j=left;j<=right;j++){
                result.push_back(matrix[top][j]);
            }top++;
            
            for(int i=top;i<=bottom;i++){
                result.push_back(matrix[i][right]);
            }right--;
            
            if(top <= bottom){
                for(int j=right;j>=left;j--){
                    result.push_back(matrix[bottom][j]);
                }bottom--;
            }
            
            if(left <= right){
                for(int i=bottom;i>=top;i--){
                    result.push_back(matrix[i][left]);
                }left++;
            }
        }
        
        return result;
    }
};
