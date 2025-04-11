// Dijkstra Algorithm (MEDIUM)
// https://www.geeksforgeeks.org/problems/implementing-dijkstra-set-1-adjacency-matrix/1

class Solution {
  public:
    vector<int> dijkstra(int V, vector<vector<int>> &edges, int src) {
        vector<vector<pair<int, int>>> adj(V);
        for (auto &edge : edges) {
            adj[edge[0]].emplace_back(edge[1], edge[2]);
            adj[edge[1]].emplace_back(edge[0], edge[2]);
        }
    
        // Distance array
        vector<int> dist(V, INT_MAX);
        dist[src] = 0;
    
        // Priority queue to store {distance, node}
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
        pq.push({0, src});
    
        while (!pq.empty()) {
            pair<int, int> top = pq.top();
            pq.pop();
            int d = top.first, u = top.second;
    
            // If the current distance is greater, skip it
            if (d > dist[u]) continue;
    
            for (auto &neighbor : adj[u]) {
                int v = neighbor.first, weight = neighbor.second;
                if (dist[u] + weight < dist[v]) {
                    dist[v] = dist[u] + weight;
                    pq.push({dist[v], v});
                }
            }
        }
    
        return dist;
        
    }
};
