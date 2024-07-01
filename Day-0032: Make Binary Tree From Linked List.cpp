// Make Binary Tree From Linked List (MEDIUM)
// https://www.geeksforgeeks.org/problems/make-binary-tree/1


/*
The structure of Link list Node is as follows
struct Node
{
    int data;
    struct node* next;

    Node(int x){
        data = x;
        next = NULL;
    }
};
The structure of TreeNode is as follows
struct TreeNode
{
    int data;
    TreeNode *left;
    TreeNode *right;
};
*/

// Function to make binary tree from linked list.
void convert(Node *head, TreeNode *&root) {
    queue<TreeNode*> que;
    TreeNode* temp = new TreeNode(head -> data);
    que.push(temp);
    head = head->next;
    root = temp;
    
    while(head){
        TreeNode* temp2 = new TreeNode(head->data);
        que.push(temp2);
        head = head->next;
        if(!que.front() -> left) que.front() -> left = temp2;
        else{
            que.front()->right = temp2;
            que.pop();
        }
    }
}
