// Is Binary Tree Heap (MEDIUM)
// https://www.geeksforgeeks.org/problems/is-binary-tree-heap/1

// Structure of node
/*class Node {
   public:
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};*/

class Solution {
  public:
    bool isHeap(Node* tree) {
        if (!tree) return true;
    
        std::queue<Node*> q;
        q.push(tree);
        
        bool nullChildSeen = false;
        
        while (!q.empty()) {
            Node* current = q.front();
            q.pop();
            
            if (current->left) {
                if (nullChildSeen || current->data < current->left->data) 
                    return false;
                q.push(current->left);
            } else {
                nullChildSeen = true;
            }
            
            if (current->right) {
                if (nullChildSeen || current->data < current->right->data)
                    return false;
                q.push(current->right);
            } else {
                nullChildSeen = true;
            }
        }
        
        return true;
        
    }
};
