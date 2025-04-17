// Minimum Weight Cycle (HARD)
// https://www.geeksforgeeks.org/problems/minimum-weight-cycle/1

class Solution {
  public:
    int findMinCycle(int V, vector<vector<int>>& edges) {
        // code here
        int minCycleWeight = INT_MAX;

    vector<vector<pair<int, int>>> graph(V);
    for (auto& edge : edges) {
        int node1 = edge[0];
        int node2 = edge[1];
        int weight = edge[2];
        graph[node1].push_back({node2, weight});
        graph[node2].push_back({node1, weight});
    }

    for (auto& edge : edges) {
        int start = edge[0], end = edge[1], edgeWeight = edge[2];
        vector<int> distances(V, INT_MAX);
        distances[start] = 0;

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
        pq.push({start, 0});

        while (!pq.empty()) {
            int currentNode = pq.top().first;
            int currentWeight = pq.top().second;
            pq.pop();

            for (auto neighbor : graph[currentNode]) {
                int neighborNode = neighbor.first;
                if ((currentNode == start && neighborNode == end) || 
                    (currentNode == end && neighborNode == start)) continue;

                int neighborWeight = neighbor.second;
                if (distances[currentNode] + neighborWeight < distances[neighborNode]) {
                    distances[neighborNode] = distances[currentNode] + neighborWeight;
                    pq.push({neighborNode, distances[neighborNode]});
                }
            }
        }

        if (distances[end] != INT_MAX) {
            minCycleWeight = min(minCycleWeight, edgeWeight + distances[end]);
        }
    }

    return minCycleWeight == INT_MAX ? -1 : minCycleWeight;
    }
};
