// Undirected Graph Cycle (MEDIUM)
// https://www.geeksforgeeks.org/problems/detect-cycle-in-an-undirected-graph/1

class Solution {
  public:
  
    bool bfs(int start, vector<bool>& vis, vector<vector<int>>& adj) {
        queue<pair<int, int>> q; 
        q.push({start, -1});
        vis[start] = true;

        while (!q.empty()) {
            int node = q.front().first;
            int parent = q.front().second;
            q.pop();

            for (int& adjnode : adj[node]) {
                if (!vis[adjnode]) {
                    q.push({adjnode, node});
                    vis[adjnode] = true;
                } else if (adjnode != parent) return true;
            }
        }

        return false;
    }

    bool isCycle(int n, vector<vector<int>>& adj) {
        vector<bool> vis(n, false);

        for (int node = 0; node < n; node++) {
            if (!vis[node]) {
                if (bfs(node, vis, adj)) return true;
            }
        }

        return false;
    }

};
