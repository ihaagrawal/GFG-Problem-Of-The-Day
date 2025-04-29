// Sort a linked list of 0s, 1s and 2s (MEDIUM)
// https://www.geeksforgeeks.org/problems/given-a-linked-list-of-0s-1s-and-2s-sort-it/1

/*  Node is defined as
  struct Node {
    int data;
    struct Node *next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};*/
class Solution {
  public:
    Node* segregate(Node* head) {
        if (!head || !head->next) return head;

        int count[3] = {0, 0, 0};
        Node* temp = head;
    
        while (temp) {
            count[temp->data]++;
            temp = temp->next;
        }
    
        temp = head;
        int index = 0;
    
        while (temp) {
            if (count[index] == 0) {
                index++;
            } else {
                temp->data = index;
                count[index]--;
                temp = temp->next;
            }
        }
    
        return head;
        
    }
};
