// Linked List Group Reverse (HARD)
// https://www.geeksforgeeks.org/problems/reverse-a-linked-list-in-groups-of-given-size/1


/*
  Node is defined as
    struct node
    {
        int data;
        struct Node* next;

        Node(int x){
            data = x;
            next = NULL;
        }

    }*head;
*/

class Solution {
  public:
    int getLength(Node* head) {
        int length = 0;
        Node* temp = head;
        while (temp != NULL) {
            length++;
            temp = temp->next;
        }
        return length;
    }  
  
    Node *reverseKGroup(Node *head, int k) {
        if (k <= 1 || head == NULL) return head;
        
        Node* currNode = head;
        Node* prevNode = NULL;
        
        int totalLength = getLength(head);
        int groups = totalLength / k;
        if (totalLength % k != 0) groups++;
        
        while (groups > 0) {
            Node* prevGroupEnd = prevNode;
            Node* currGroupStart = currNode;
        
            Node* nextNode = currNode->next;
            for (int i = 0; currNode != NULL && i < k; i++) {
                currNode->next = prevNode;
                prevNode = currNode;
                currNode = nextNode;
                if (nextNode != NULL) nextNode = nextNode->next;
            }
        
            if (prevGroupEnd != NULL) prevGroupEnd->next = prevNode;
            else head = prevNode;
        
            currGroupStart->next = currNode;
            prevNode = currGroupStart;
            groups--;
        }
        return head;

    }
};
