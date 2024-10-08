// Middle of a Linked List (EASY)
// https://www.geeksforgeeks.org/problems/finding-middle-element-in-a-linked-list/1

/* Link list Node
struct Node {
    int data;
    Node* next;

    Node(int x){
        data = x;
        next = NULL;
    }

}; */
class Solution {
  public:
    /* Should return data of middle node. If linked list is empty, then -1 */
    int getMiddle(Node* head) {
        Node* fast = head;
        Node* slow = head;
        
        while(fast && fast->next){
            fast = fast->next->next;
            slow = slow->next;
        }
        
        return slow->data;
    }
};
