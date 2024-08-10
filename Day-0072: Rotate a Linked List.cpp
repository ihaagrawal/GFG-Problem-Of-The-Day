// Rotate a Linked List (MEDIUM)
// https://www.geeksforgeeks.org/problems/rotate-a-linked-list/1

/*

struct Node {
    int data;
    struct Node *next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

*/

class Solution {
  public:
    // Function to rotate a linked list.
    Node* rotate(Node* head, int k) {
        Node* temp1 = new Node(-1),*temp2=new Node(-1);
        Node* head1 = temp1,*head2 = temp2;
        while(head){
            if(k){
                temp1->next = head;
                temp1 = temp1->next;
                k--;
            }else{
                temp2->next = head;
                temp2 = temp2->next;
            }
            head = head->next;
                temp1->next = nullptr;
                temp2->next = nullptr;
        }
        temp2->next = head1->next;
        return head2->next;
    }
};
