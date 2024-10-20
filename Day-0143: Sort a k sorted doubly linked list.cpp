// Sort a k sorted doubly linked list (EASY)
// https://www.geeksforgeeks.org/problems/sort-a-k-sorted-doubly-linked-list/1


/*
// a node of the doubly linked list
class DLLNode
{
public:
    int data;
    DLLNode *next;
    DLLNode *prev;
    DLLNode(int val)
    {
        data = val;
        this->next = NULL;
        this->prev = NULL;
    }
};
*/
class Solution {
  public:
  
    struct compare {
        bool operator()(DLLNode* a, DLLNode* b) {
            return a->data > b->data;
        }
    };
  
    // function to sort a k sorted doubly linked list
    DLLNode *sortAKSortedDLL(DLLNode *head, int k) {
        if (!head) return nullptr;

        priority_queue<DLLNode*, vector<DLLNode*>, compare> minHeap;
    
        DLLNode* newHead = nullptr;
        DLLNode* last = nullptr;
    
        DLLNode* curr = head;
        for (int i = 0; curr != nullptr && i <= k; ++i) {
            minHeap.push(curr);
            curr = curr->next;
        }
    
        while (!minHeap.empty()) {
            DLLNode* minNode = minHeap.top();
            minHeap.pop();
    
            if (!newHead) {
                newHead = minNode;
                last = newHead;
            } else {
                last->next = minNode;
                minNode->prev = last;
                last = minNode;
            }
    
            if (curr != nullptr) {
                minHeap.push(curr);
                curr = curr->next;
            }
        }
    
        last->next = nullptr;
    
        return newHead;
    }
};
