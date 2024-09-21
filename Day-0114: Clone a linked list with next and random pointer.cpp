// Clone a linked list with next and random pointer (HARD)
// https://www.geeksforgeeks.org/problems/clone-a-linked-list-with-next-and-random-pointer/1


/* Link list Node
struct Node {
    int data;
    Node *next;
    Node *random;

    Node(int x) {
        data = x;
        next = NULL;
        random = NULL;
    }
};*/

class Solution {
  public:
    Node *copyList(Node *head) {
        return head;
    }
};
