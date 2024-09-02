// Minimum Cost Path (HARD)
// https://www.geeksforgeeks.org/problems/minimum-cost-path3833/1

class Solution
{
    public:
    bool check(int r,int c,int n){
        if(r >= 0 && r < n && c >= 0 && c < n)return true;
        else return false;
    }
    
    int minimumCostPath(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<int>>dist(n, vector<int>(n,INT_MAX));
        
        priority_queue<pair<int,pair<int,int>>, vector<pair<int,pair<int,int>>>, greater<pair<int,pair<int,int>>>>pq;
        
        dist[0][0]=grid[0][0];
        pq.push({grid[0][0],{0,0}});
        
        int row_dir[4]={-1, 0, 1, 0};
        int col_dir[4]={0, 1, 0, -1};
        
        while(!pq.empty()){
            auto it = pq.top();
            pq.pop();
            
            int wt = it.first, row = it.second.first, col = it.second.second;
            
            for(int i=0;i<4;i++){
                int newrow = row + row_dir[i];
                int newcol = col + col_dir[i];
                
                if(check(newcol, newrow, n) && wt + grid[newrow][newcol] < dist[newrow][newcol]){
                    dist[newrow][newcol] = wt + grid[newrow][newcol];
                    pq.push({wt + grid[newrow][newcol], {newrow, newcol}});
                }
            }
        }
        
        return dist[n-1][n-1];
    }
};
