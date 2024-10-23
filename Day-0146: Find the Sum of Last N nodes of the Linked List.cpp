// Find the Sum of Last N nodes of the Linked List (EASY)
// https://www.geeksforgeeks.org/problems/find-the-sum-of-last-n-nodes-of-the-linked-list/1


class Solution {
  public:
    /*Structure of the node of the linled list is as

    struct Node {
        int data;
        struct Node* next;

        Node(int x){
            data = x;
            next = NULL;
        }
    };
    */
    // your task is to complete this function
    // function should return sum of last n nodes
    int sumOfLastN_Nodes(struct Node* head, int n) {
       int count=0;
       Node* temp=head;
       
       while(temp!=nullptr){
           count++;
           temp=temp->next;
       }
       
       int diff=abs(count-n);
       temp=head;
       
       for(int i=1;i<=diff;i++){
           temp=temp->next;
       }
       
       int sum=0;
       while(temp!=nullptr){
           sum+=temp->data;
           temp=temp->next;
       }
       return sum;
    }
};
