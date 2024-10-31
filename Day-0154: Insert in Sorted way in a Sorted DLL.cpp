// Insert in Sorted way in a Sorted DLL (MEDIUM)
// https://www.geeksforgeeks.org/problems/insert-in-sorted-way-in-a-sorted-dll/1


/*structure of the node of the DLL is as
struct Node {
    int data;
    struct Node* prev, *next;
};
*/
// function should insert a new node in sorted way in
// a sorted doubly linked list
// Return the head after insertion
class Solution {
  public:
    Node* sortedInsert(Node* head, int x) {
        Node *node = new Node;
        node->data = x;
        node->prev = NULL;
        node->next = NULL;
        
        Node *pre = NULL;
        Node *curr = head;
        
        if(curr->data >= x){
            node->next = curr;
            return node;
        }
        
        
        while(curr != NULL){
            if(curr->data <= x){
                pre = curr;
                curr = curr->next;
            }else break;
        }
        
        
        pre->next = node;
        pre = pre->next;
        pre->next = curr;
        return head;
        
    }
};
