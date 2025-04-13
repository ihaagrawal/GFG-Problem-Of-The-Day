// Clone an Undirected Graph (MEDIUM)
// https://www.geeksforgeeks.org/problems/clone-graph/1

// User function Template for C++

// struct Node {
//     int val;
//     vector<Node*> neighbors;
//     Node() {
//         val = 0;
//         neighbors = vector<Node*>();
//     }
//     Node(int _val) {
//         val = _val;
//         neighbors = vector<Node*>();
//     }
//     Node(int _val, vector<Node*> _neighbors) {
//         val = _val;
//         neighbors = _neighbors;
//     }
// };

class Solution {
  public:
    Node* cloneGraph(Node* node) {
        if (!node) return nullptr;

        unordered_map<Node*, Node*> cloneMap;

        queue<Node*> q;
        q.push(node);

        cloneMap[node] = new Node(node->val);

        while (!q.empty()) {
            Node* current = q.front();
            q.pop();

            for (Node* neighbor : current->neighbors) {
                if (cloneMap.find(neighbor) == cloneMap.end()) {
                    cloneMap[neighbor] = new Node(neighbor->val);
                    q.push(neighbor); 
                }
                cloneMap[current]->neighbors.push_back(cloneMap[neighbor]);
            }
        }

        return cloneMap[node];
        
    }
};
