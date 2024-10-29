// Quick Sort on Linked List (MEDIUM)
// https://www.geeksforgeeks.org/problems/quick-sort-on-linked-list/1


/* a node of the singly linked list
struct node
{
    int data;
    struct node *next;

    node(int x){
        data = x;
        next = NULL;
    }
}; */

// Solution class with quickSort function
class Solution {
  public:
    void swap(struct Node* left, struct Node* right) {
        int temp = left->data;
        left->data = right->data;
        right->data = temp;
    }
    
    void sort(struct Node *start, struct Node* end = NULL) {
        if(start == end) return;
        struct Node* pivot = start;
        struct Node* s = pivot->next;
        struct Node* b = pivot;
        while(s != end) {
            if(s->data < pivot->data) {
                b = b->next;
                swap(s, b);
            }
            s = s->next;
        }
        swap(pivot, b);
        
        sort(start, b);
        sort(b->next, NULL);
    }
    struct Node* quickSort(struct Node* head) {
        sort(head);
        return head;
    }
};
