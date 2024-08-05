// Bottom View of Binary Tree (MEDIUM)
// https://www.geeksforgeeks.org/problems/bottom-view-of-binary-tree/1


class Solution {
  public:
    vector <int> bottomView(Node *root) {
        vector<int> result;
        if(!root) return result;
        map<int, int> mp;
        queue<pair<int, Node*>> que;
        
        que.push({0, root});
        while(!que.empty()){
            pair<int, Node*> front = que.front();
            que.pop();
            
            int x = front.first;
            Node* node = front.second;
            
            mp[x] = node->data;
            
            if(node->left) que.push({x-1, node->left});
            if(node->right) que.push({x+1, node->right});
        }
        
        for(auto it : mp) result.push_back(it.second);
        
        return result;
    }
};
