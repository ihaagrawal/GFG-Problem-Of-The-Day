// Identical Linked Lists (BASIC)
// https://www.geeksforgeeks.org/problems/identical-linked-lists/1

bool areIdentical(struct Node *head1, struct Node *head2) {
    while(head1 && head2){
        if(head1->data != head2->data) return false;
        head1 = head1->next;
        head2 = head2->next;
    }
    return (!head1 && !head2);
}
