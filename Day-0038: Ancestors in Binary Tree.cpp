// Ancestors in Binary Tree (MEDIUM)
// https://www.geeksforgeeks.org/problems/ancestors-in-binary-tree/1


class Solution {
  public:
    // Function should return all the ancestor of the target node
    vector<int> Ancestors(struct Node *root, int target) {
        vector<int> result;
        if(!root) return result;
        
        map<Node*, Node*> mp;
        queue<Node*> que;
        
        Node* front;
        que.push(root);
        
        while(!que.empty()){
            front = que.front();
            que.pop();
            if(front->data == target) break;
            if(front->left){
                que.push(front->left);
                mp[front->left] = front;
            }
            if(front->right){
                que.push(front->right);
                mp[front->right] = front; 
            }
        }
        
        Node* temp = front;
        while(temp != root){
            result.push_back(mp[temp]->data);
            temp = mp[temp];
        }
        
        return result;
    }
};
