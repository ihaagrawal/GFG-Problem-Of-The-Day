// BFS of graph (EASY)
// https://www.geeksforgeeks.org/problems/bfs-traversal-of-graph/1

class Solution {
  public:
    // Function to return Breadth First Traversal of given graph.
    vector<int> bfs(vector<vector<int>> &adj) {
        int n = adj.size();
        vector<bool> vis(n, false);
        vector<int> result;
        queue<int> q;
        
        q.push(0);
        vis[0] = true;
        
        while(!q.empty()){
            int node = q.front();
            result.push_back(node);
            q.pop();

            for(int& adjnode : adj[node]){
                if(!vis[adjnode]){
                    vis[adjnode] = true;
                    q.push(adjnode);
                }
            }
        }
        
        return result;
        
    }
};
