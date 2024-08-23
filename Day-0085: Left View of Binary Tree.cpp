// Left View of Binary Tree (EASY)
// https://www.geeksforgeeks.org/problems/left-view-of-binary-tree/1


/* A binary tree node

struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
    
    Node(int x){
        data = x;
        left = right = NULL;
    }
};
 */

//Function to return a list containing elements of left view of the binary tree.
vector<int> leftView(Node *root){
   vector<int> result;
    
    queue<Node*> q;
    q.push(root);
    
    while(!q.empty()){
        int n=q.size();
        result.push_back(q.front()->data);
        
        while(n--){
            auto x=q.front();
            q.pop();
            
            if(x->left) q.push(x->left);
            if(x->right) q.push(x->right);
        }
        
    }
    return result;
}
