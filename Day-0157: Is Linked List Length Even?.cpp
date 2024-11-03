// Is Linked List Length Even? (BASIC)
// https://www.geeksforgeeks.org/problems/linked-list-length-even-or-odd/1


/*structure of a node of the linked list is as
struct Node
{
    int data;
    struct Node* next;

    Node(int x){
        data = x;
        next = NULL;
    }

};
*/
class Solution {
  public:
    bool isLengthEven(struct Node **head) {
        Node* fast = *head;
       while(true){
           if(!fast->next)return false;
           if(!fast->next->next)return true;
           fast = fast->next->next;
       }
    }
};
