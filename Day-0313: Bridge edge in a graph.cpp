// Bridge edge in a graph (MEDIUM)
// https://www.geeksforgeeks.org/problems/bridge-edge-in-graph/1


class Solution {
  public:
    void dfs(int node, vector<int> adj[], vector<bool>& visited) {
        visited[node] = true;
        for (int neighbor : adj[node]) {
            if (!visited[neighbor]) {
                dfs(neighbor, adj, visited);
            }
        }
    }

    int countComponents(int V, vector<int> adj[]) {
        vector<bool> visited(V, false);
        int components = 0;
        for (int i = 0; i < V; ++i) {
            if (!visited[i]) {
                components++;
                dfs(i, adj, visited);
            }
        }
        return components;
    }

    bool isBridge(int V, vector<vector<int>> &edges, int c, int d) {
        vector<int> adj[V];

        for (const auto& edge : edges) {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }

        int initialComponents = countComponents(V, adj);

        adj[c].erase(remove(adj[c].begin(), adj[c].end(), d), adj[c].end());
        adj[d].erase(remove(adj[d].begin(), adj[d].end(), c), adj[d].end());

        int newComponents = countComponents(V, adj);

        return newComponents > initialComponents;
    }
};
