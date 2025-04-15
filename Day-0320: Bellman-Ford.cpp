// Bellman-Ford (MEDIUM)
// https://www.geeksforgeeks.org/problems/distance-from-the-source-bellman-ford-algorithm/1

class Solution {
  public:
    vector<int> bellmanFord(int V, vector<vector<int>>& edges, int S) {
        vector<int> distTo(V, 1e8);
        vector<int> parent(V, -1);
        
        distTo[S]=0;
        
        for(int i=0;i<V-1;i++){
            for(auto it: edges){
                int u=it[0], v=it[1], wt=it[2];
                if(distTo[u]!=1e8 && distTo[u]+wt<distTo[v]){
                    distTo[v]=distTo[u]+wt;
                    parent[v]=u;
                }
            }
        }
        
        for(auto it:edges){
            int u=it[0], v=it[1], wt=it[2];
                if(distTo[u]!=1e8 && distTo[u]+wt<distTo[v]) return { -1};
        }
        
        return distTo;
        
    }
};
