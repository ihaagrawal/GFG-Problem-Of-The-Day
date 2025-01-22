// Add Number Linked Lists (MEDIUM)
// https://www.geeksforgeeks.org/problems/add-two-numbers-represented-by-linked-lists/1

/* node for linked list:

struct Node {
    int data;
    struct Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

*/

class Solution {
  public:
    Node* reverseList(Node* head) {
        Node* prev = nullptr;
        Node* current = head;
        while (current != nullptr) {
            Node* nextNode = current->next;
            current->next = prev;
            prev = current;
            current = nextNode;
        }
        return prev;
    }

    Node* addTwoLists(Node* num1, Node* num2) {
        num1 = reverseList(num1);
        num2 = reverseList(num2);

        Node* dummy = new Node(0);
        Node* current = dummy;
        int carry = 0;

        while (num1 != nullptr || num2 != nullptr || carry != 0) {
            int sum = carry;
            if (num1 != nullptr) {
                sum += num1->data;
                num1 = num1->next;
            }
            if (num2 != nullptr) {
                sum += num2->data;
                num2 = num2->next;
            }
            carry = sum / 10;
            current->next = new Node(sum % 10);
            current = current->next;
        }

        Node* result = reverseList(dummy->next);
        delete dummy;

        while (result != nullptr && result->data == 0 && result->next != nullptr) {
            Node* temp = result;
            result = result->next;
            delete temp;
        }

        return result;
    }
};
