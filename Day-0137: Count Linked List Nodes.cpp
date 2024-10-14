// Count Linked List Nodes (BASIC)
// https://www.geeksforgeeks.org/problems/count-nodes-of-linked-list/1

/*
struct Node
{
    int data;
    Node* next;
    Node(int x) {  data = x;  next = NULL; }
}; */

class Solution {
  public:
    // Function to count nodes of a linked list.
    int getCount(struct Node* head) {
        Node* temp = head;
        int count = 0;
        
        while(temp){
            temp = temp->next;
            count++;
        }
        
        return count;
    }
};
