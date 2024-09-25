// Palindrome Linked List (MEDIUM)
// https://www.geeksforgeeks.org/problems/check-if-linked-list-is-pallindrome/1


/*
struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
};
*/

class Solution {
  public:
    // Function to check whether the list is palindrome.
    bool isPalindrome(Node *head) {
        vector<int> nodeValues;
        while(head) {
            nodeValues.push_back(head->data);
            head = head->next;
        }
        
        vector<int> reversedNodeValues = nodeValues;
        reverse(reversedNodeValues.begin(), reversedNodeValues.end());
        
        return (nodeValues == reversedNodeValues);

    }
};
