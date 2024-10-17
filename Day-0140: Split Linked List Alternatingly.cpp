// Split Linked List Alternatingly (EASY)
// https://www.geeksforgeeks.org/problems/split-singly-linked-list-alternatingly/1


/*
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
    // Function to split a linked list into two lists alternately
    vector<Node*> alternatingSplitList(struct Node* head) {
        Node* list1 = nullptr;
        Node* list2 = nullptr;
        
        Node* tail1 = nullptr;
        Node* tail2 = nullptr;
        
        bool alternate = true;
    
        while (head != nullptr) {
            if (alternate) {
                if (list1 == nullptr) {
                    list1 = head;
                    tail1 = head;
                } else {
                    tail1->next = head;
                    tail1 = tail1->next;
                }
            } else {
                if (list2 == nullptr) {
                    list2 = head;
                    tail2 = head;
                } else {
                    tail2->next = head;
                    tail2 = tail2->next;
                }
            }
    
            head = head->next;
            alternate = !alternate;
        }
    
        if (tail1 != nullptr) tail1->next = nullptr;
        if (tail2 != nullptr) tail2->next = nullptr;
    
        return {list1, list2};
    }
};
