// Alien Dictionary (HARD)
// https://www.geeksforgeeks.org/problems/alien-dictionary/1

class Solution{
    void dfs(int v, vector<vector<int>>& adj, vector<bool>& visited, string& order) {
        visited[v] = true;
        for (int u : adj[v]) {
            if (!visited[u]) {
                dfs(u, adj, visited, order);
            }
        }
        order = char(v + 'a') + order;
    }

public:
    string findOrder(string dict[], int N, int K) {
        vector<vector<int>> adj(K);
        vector<bool> visited(K, false);
        string order;

        for (int i = 0; i < N - 1; i++) {
            string w1 = dict[i], w2 = dict[i + 1];
            for (int j = 0; j < min(w1.length(), w2.length()); j++) {
                if (w1[j] != w2[j]) {
                    adj[w1[j] - 'a'].push_back(w2[j] - 'a');
                    break;
                }
            }
        }

        for (int i = 0; i < K; i++) {
            if (!visited[i]) {
                dfs(i, adj, visited, order);
            }
        }

        return order;
    }
};
