// Remove all occurences of duplicates in a linked list (MEDIUM)
// https://www.geeksforgeeks.org/problems/remove-all-occurences-of-duplicates-in-a-linked-list/1


/* Linked List node structure

struct Node {
    int data;
    struct Node *next;
};

*/

class Solution {
  public:
    Node* removeAllDuplicates(struct Node* head) {
        if(!head) return nullptr;
        
        Node dummy(0);
        dummy.next = head;
        Node* temp = head;
        Node* prev = &dummy;
        
        while(temp){
            bool duplicate = false;
            
            while(temp->next && temp->data == temp->next->data){
                duplicate = true;
                temp = temp->next;
            }
            
            if(duplicate) prev->next = temp->next;
            else prev = prev->next;
            
            temp = temp->next;
        }
        
        return dummy.next;
    }
};
