// Construct Binary Tree from Parent Array (MEDIUM)
// https://www.geeksforgeeks.org/problems/construct-binary-tree-from-parent-array/1


struct Node
{
    int data;
    struct Node* left;
    struct Node* right;

    Node(int x){
        data = x;
        left = right = NULL;
    }
}; */

class Solution {
  public:
    Node *createTree(vector<int> parent) {
        int n=parent.size();
        unordered_map<int,Node*> mp;
        for(int i=0;i<n;i++)
        {
            int par=parent[i];
            int child=i;
            if(mp.find(par)==mp.end()) mp[par]=new Node(par);
            if(mp.find(child)==mp.end()) mp[child]=new Node(child);
            if(mp[par]->left==NULL&&mp[par]->right==NULL) mp[par]->left=mp[child];
            else if(mp[par]->left==NULL) mp[par]->left=mp[child];
            else mp[par]->right=mp[child];
        }
        return mp[-1]->left;
    }
};
