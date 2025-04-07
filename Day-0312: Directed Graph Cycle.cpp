// Directed Graph Cycle (MEDIUM)
// https://www.geeksforgeeks.org/problems/detect-cycle-in-a-directed-graph/1

class Solution {
  public:
    bool dfs(int i, vector<vector<int>> &adj, vector<bool> &vis1, vector<bool> &vis2) {
        vis1[i] = true;
        vis2[i] = true;  // recursion stack

        for (int neighbor : adj[i]) {
            if (!vis1[neighbor]) {
                if (dfs(neighbor, adj, vis1, vis2)) 
                    return true;
            } else if (vis2[neighbor]) {
                // back edge found => cycle
                return true;
            }
        }

        vis2[i] = false;  // backtrack
        return false;
    }

    bool isCyclic(int V, vector<vector<int>> &edges) {
        vector<vector<int>> adj(V);
        for (auto &edge : edges) {
            adj[edge[0]].push_back(edge[1]);  // build adjacency list
        }

        vector<bool> vis1(V, false), vis2(V, false);
        for (int i = 0; i < V; ++i) {
            if (!vis1[i]) {
                if (dfs(i, adj, vis1, vis2)) 
                    return true;
            }
        }

        return false;
    }
};
