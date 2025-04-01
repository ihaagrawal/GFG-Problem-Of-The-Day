// DFS of Graph (EASY)
// https://www.geeksforgeeks.org/problems/depth-first-traversal-for-a-graph/1

class Solution {
  public:
    void dfs(vector<vector<int>>& adj, vector<int>& result, vector<bool>& vis, int node){
        if(vis[node]) return;
        
        result.push_back(node);
        vis[node] = true;
        for(int& adjnode : adj[node]){
            if(!vis[adjnode]) dfs(adj, result, vis, adjnode);
        }
    }
    
    vector<int> dfs(vector<vector<int>>& adj) {
        int n = adj.size();
        vector<int> result;
        vector<bool> vis(n, false);
        
        dfs(adj, result, vis, 0);
        return result;
    }
};
