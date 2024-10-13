// Delete Alternate Nodes (Easy)
// https://www.geeksforgeeks.org/problems/delete-alternate-nodes/1


/*
Structure of the node of the binary tree
struct Node
{
    int data;
    struct Node *next;

    Node(int x){
        int data = x;
        next = NULL;
    }
};
*/
// Complete this function
class Solution {
  public:
    void deleteAlt(struct Node *head) {
        Node*temp = head;
        while(temp && temp->next){
            temp->next = temp->next->next;
            temp = temp->next;
        }
    }
};
