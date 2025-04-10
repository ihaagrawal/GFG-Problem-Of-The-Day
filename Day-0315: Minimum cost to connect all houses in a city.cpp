// Minimum cost to connect all houses in a city (MEDIUM)
// https://www.geeksforgeeks.org/problems/minimum-cost-to-connect-all-houses-in-a-city/1

class Solution {
  public:
    int minCost(vector<vector<int>>& houses) {
        int n = houses.size();
        vector<bool> visited(n, false);
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
        pq.push({0, 0}); 
        int totalCost = 0, connected = 0;

        while (connected < n) {
            pair<int, int> top = pq.top();
            pq.pop();
            int cost = top.first;
            int u = top.second;

            if (visited[u]) continue;
            visited[u] = true;
            totalCost += cost;
            connected++;

            for (int v = 0; v < n; v++) {
                if (!visited[v]) {
                    int dist = abs(houses[u][0] - houses[v][0]) + abs(houses[u][1] - houses[v][1]);
                    pq.push({dist, v});
                }
            }
        }

        return totalCost;
        
    }
};
