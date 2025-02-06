// Construct Tree from Inorder & Preorder (MEDIUM)
// https://www.geeksforgeeks.org/problems/construct-tree-1/1


/*
Definition of the Node class
class Node {
public:
    int data;
    Node *left;
    Node *right;

    Node(int x) {
        data = x;
        left = NULL;
        right = NULL;
    }
};
*/
class Solution {
  public:
    // Function to build the tree from given inorder and preorder traversals
    // Helper function to build the tree
    Node* buildTreeHelper(vector<int>& preorder, int preStart, int preEnd, 
                          vector<int>& inorder, int inStart, int inEnd, 
                          unordered_map<int, int>& inMap) {
        if (preStart > preEnd || inStart > inEnd) return nullptr;
    
        // The first element of preorder is the root
        int rootVal = preorder[preStart];
        Node* root = new Node(rootVal);
    
        // Find the index of the root in inorder traversal
        int inRoot = inMap[rootVal];
        int numsLeft = inRoot - inStart;
    
        // Recursively build left and right subtrees
        root->left = buildTreeHelper(preorder, preStart + 1, preStart + numsLeft, 
                                     inorder, inStart, inRoot - 1, inMap);
        root->right = buildTreeHelper(preorder, preStart + numsLeft + 1, preEnd, 
                                      inorder, inRoot + 1, inEnd, inMap);
    
        return root;
    }
    
    // Main function to build the tree
    Node* buildTree(vector<int>& inorder, vector<int>& preorder) {
        unordered_map<int, int> inMap;
        for (int i = 0; i < inorder.size(); ++i) {
            inMap[inorder[i]] = i;
        }
        return buildTreeHelper(preorder, 0, preorder.size() - 1, 
                               inorder, 0, inorder.size() - 1, inMap);
    }
    
};
