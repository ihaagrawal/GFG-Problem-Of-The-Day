// Occurence of an integer in a Linked List (EASY)
// https://www.geeksforgeeks.org/problems/occurence-of-an-integer-in-a-linked-list/1


/*
  Node is defined as
struct node
{
    int data;
    struct node* next;

    node(int x){
        data = x;
        next = NULL;
    }
}*head;
*/
class Solution {
  public:
    int count(struct Node* head, int key) {
        int result = 0;
        Node* temp = head;
        
        while(temp){
            if(temp->data == key) result++; 
            temp = temp->next;
        }
        
        return result;
    }
};
