// Circle of strings (HARD)
// https://www.geeksforgeeks.org/problems/circle-of-strings4530/1

class Solution {
  public:
  
    void dfs(int node, vector<int> adj[], vector<int>& visited){
        visited[node] = 1;
        for(auto adjnode : adj[node]){
            if(!visited[adjnode]){
                dfs(adjnode, adj, visited);
            }
        }
    } 
  
    int isCircle(vector<string> &arr) {
        int n = arr.size();
        vector<int> adj[26];
        vector<int> in(26, 0), out(26, 0);
        
        for(int i=0;i<n;i++){
            string temp = arr[i];
            int u = temp[0] - 'a';  
            int v = temp[temp.size() - 1] - 'a';
            adj[u].push_back(v);
            out[u]++;
            in[v]++;
        }
        
        for(int i=0;i<26;i++){
            if(in[i] != out[i]) return 0;
        }
        
        vector<int> visited(26, 0);
        int node = arr[0][0] - 'a';
        dfs(node, adj, visited);
        
        for(int i=0;i<26;i++){
            if(in[i] != 0 && !visited[i]) return 0;
        }
        
        return 1;
    }
};
