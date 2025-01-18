// Reverse a linked list (EASY)
// https://www.geeksforgeeks.org/problems/reverse-a-linked-list/1


/* Linked List Node structure:

struct Node
{
    int data;
    struct Node *next;
}

*/

class Solution {
  public:
    Node* reverseList(struct Node* head) {
        Node* prev = nullptr;
        Node* current = head;
        
        while (current != nullptr) {
            Node* next = current->next;
            current->next = prev;
            prev = current;
            current = next;
        }
        
        return prev;
    }
};
