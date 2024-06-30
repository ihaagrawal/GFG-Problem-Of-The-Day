// Delete node in Doubly Linked List (EASY)
// https://www.geeksforgeeks.org/problems/delete-node-in-doubly-linked-list/1

/* Structure of Node
struct Node
{
  int data;
  struct Node *next;
  struct Node *prev;

  Node(int x){
      data = x;
      next = NULL;
      prev = NULL;
  }

};
*/

class Solution {
  public:
    Node* deleteNode(Node* head, int x) {
        if(x == 1) return head->next;
        Node* temp = head;

        for(int i=1;i<x-1;i++) temp = temp->next;
        
        Node* temp2 = temp->next;
        temp->next = temp2->next;
        if(temp2->next) temp2->next->prev = temp;
        return head;
    }
};
