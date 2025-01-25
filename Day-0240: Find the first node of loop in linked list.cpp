// Find the first node of loop in linked list (EASY)
// https://www.geeksforgeeks.org/problems/find-the-first-node-of-loop-in-linked-list--170645/1


/*struct Node
{
    int data;
    struct Node *next;
    Node(int x) {
        data = x;
        next = NULL;
    }

*/
class Solution {
  public:
    Node* findFirstNode(Node* head) {
        if (!head || !head->next) return NULL; // No loop possible in empty list or single-node list

        Node* slow = head;
        Node* fast = head;

        // Step 1: Detect if a loop exists using Floyd's Cycle Detection
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;

            if (slow == fast) {
                // Step 2: Find the first node of the loop
                slow = head;
                while (slow != fast) {
                    slow = slow->next;
                    fast = fast->next;
                }
                return slow; // First node of the loop
            }
        }

        return NULL; // No loop found
    }
};
