// Insert in Sorted Circular Linked List (MEDIUM)
// https://www.geeksforgeeks.org/problems/sorted-insert-for-circular-linked-list/1

/* structure for a node
class Node {
 public:
  int data;
  Node *next;

  Node(int x){
      data = x;
      next = NULL;
  }
}; */

class Solution {
  public:
    Node* sortedInsert(Node* head, int data) {
        Node* newNode = new Node(data);

        if (!head) {
            newNode->next = newNode;
            return newNode;
        }

        Node* current = head;

        if (data <= head->data) {
            while (current->next != head) current = current->next;
            newNode->next = head;
            current->next = newNode;
            return newNode;
        }

        while (current->next != head && current->next->data < data) current = current->next;

        newNode->next = current->next;
        current->next = newNode;

        return head;
    }
};
