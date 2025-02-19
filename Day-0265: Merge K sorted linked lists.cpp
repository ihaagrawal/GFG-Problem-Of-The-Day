// Merge K sorted linked lists (MEDIUM)
// https://www.geeksforgeeks.org/problems/merge-k-sorted-linked-lists/1


/*Linked list Node structure

struct Node
{
    int data;
    Node* next;

    Node(int x){
        data = x;
        next = NULL;
    }

};
*/

class Solution {
  public:
    Node* mergeKLists(vector<Node*>& arr) {
        int n = arr.size();
        priority_queue<int, vector<int>, greater<int>> minHeap;
        
        for(auto it : arr){
            while(it){
                minHeap.push(it->data);
                it = it->next;
            }
        }
         
        Node* result = new Node(0);
        Node* temp = result;
        while(!minHeap.empty()){
            Node* newnode = new Node(minHeap.top());
            minHeap.pop();
            temp->next = newnode;
            temp = temp->next;
        }
        
        return result->next;
    }
};
