// Articulation Point - II (HARD)
// https://www.geeksforgeeks.org/problems/articulation-point2616/1

class Solution {
  public:
    void dfs(int u, int parent, vector<int>& disc, vector<int>& low, vector<int>& ap, vector<int> adj[], int& time) {
        disc[u] = low[u] = ++time;
        int children = 0;

        for (int v : adj[u]) {
            if (disc[v] == -1) {
                ++children;
                dfs(v, u, disc, low, ap, adj, time);

                low[u] = min(low[u], low[v]);

                if (parent == -1 && children > 1) ap[u] = 1; // Root case
                if (parent != -1 && low[v] >= disc[u]) ap[u] = 1; // Non-root case
            } else if (v != parent) {
                low[u] = min(low[u], disc[v]);
            }
        }
    }

    vector<int> articulationPoints(int V, vector<vector<int>>& edges) {
        vector<int> adj[V];
        for (const auto& edge : edges) {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }

        vector<int> disc(V, -1), low(V, -1), ap(V, 0);
        int time = 0;

        for (int i = 0; i < V; ++i) {
            if (disc[i] == -1) {
                dfs(i, -1, disc, low, ap, adj, time);
            }
        }

        vector<int> result;
        for (int i = 0; i < V; ++i) {
            if (ap[i] == 1) result.push_back(i);
        }

        if (result.empty()) return {-1};
        return result;
    }
};
