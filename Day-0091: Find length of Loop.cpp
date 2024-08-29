// Find length of Loop (EASY)
// https://www.geeksforgeeks.org/problems/find-length-of-loop/1

class Solution {
  public:
    // Function to find the length of a loop in the linked list.
    int countNodesinLoop(struct Node *head) {
        Node *slow = head;
        Node *fast = head;

        while (fast != nullptr && fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;

            if (slow == fast) {
                int count = 1;
                Node *temp = slow;
                while (temp->next != slow) {
                    count++;
                    temp = temp->next;
                }
                return count;
            }
        }

        return 0;
    }
};
