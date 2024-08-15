// Add 1 to a Linked List Number (MEDIUM)
// https://www.geeksforgeeks.org/problems/add-1-to-a-number-represented-as-linked-list/1


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
    Node* addOne(Node* head) {
        Node* temp = head;
        Node* prev = nullptr;
        int carry = 0;
        bool flag = true;
        
        while(temp){
            Node* current = temp->next;
            temp->next = prev;
            prev = temp;
            temp = current;
        }
        
        temp = prev;
        prev = nullptr;
    
        while(temp){
            if(flag){
                int add = temp->data + 1 + carry;
                temp->data = add % 10;
                carry = add / 10;
                flag = false;
            }else{
                int add = temp->data + carry;
                temp->data = add % 10;
                carry = add / 10;
            }
            Node* current = temp->next;
            temp->next = prev;
            prev = temp;
            temp = current;
        }
        
        if(carry > 0){
            Node* newnode = new Node(carry);
            newnode->next = prev;
            return newnode;
        }else return prev;
    }
};
