// Row with max 1s (MEDIUM)
// https://www.geeksforgeeks.org/problems/row-with-max-1s0023/1

class Solution {
  public:
    int rowWithMax1s(vector<vector<int>> arr) {
        int n = arr.size(), m = arr[0].size();
        int maxCount = 0, index = -1;
        
        for(int i=0;i<n;i++){
            int count = 0;
            for(int j=0;j<m;j++){
                if(arr[i][j] == 1) count++;
            }
            if(count > maxCount){
                maxCount = count;
                index = i;
            }
        }
        
        return index;
    }
};
