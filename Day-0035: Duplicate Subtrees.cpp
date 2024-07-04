// Duplicate Subtrees (MEDIUM)
// https://www.geeksforgeeks.org/problems/duplicate-subtrees/1


class Solution {
  public:
    map<string, int> mp;
    vector<Node*> result;
    
    string fun(Node* root){
        if(!root) return "$";
        
        string str = "";
        
        str += to_string(root->data) + "/";
        str += fun(root->left) + '/';
        str += fun(root->right) + '/';
        
        mp[str]++;
        if(mp[str] == 2) result.push_back(root);
        return str;
    }
    
    vector<Node*> printAllDups(Node* root) {
        fun(root);
        return result;
    }
};
