// Remove loop in Linked List (MEDIUM)
// https://www.geeksforgeeks.org/problems/remove-loop-in-linked-list/1


/*
structure of linked list node:

struct Node
{
    int data;
    Node* next;

    Node(int val)
    {
        data = val;
        next = NULL;
    }
};

*/

class Solution {
  public:
    // Function to remove a loop in the linked list.
    void removeLoop(Node* head) {
        if (!head || !head->next) return;

        Node* slow = head;
        Node* fast = head;

        // Detect the loop using Floyd's Cycle Detection Algorithm
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;

            // If slow and fast meet, a loop is detected
            if (slow == fast) {
                break;
            }
        }

        // If no loop is found, return
        if (slow != fast) return;

        // Find the start of the loop
        slow = head;
        if (slow == fast) {
            // Special case: The loop starts at the head
            while (fast->next != slow) {
                fast = fast->next;
            }
        } else {
            while (slow->next != fast->next) {
                slow = slow->next;
                fast = fast->next;
            }
        }

        // Break the loop
        fast->next = NULL;
    }
};
