// XOR Linked List (MEDIUM)
// https://www.geeksforgeeks.org/problems/xor-linked-list/1

/*
Structure of linked list is as
struct Node
{
    int data;
    struct Node* npx;

    Node(int x){
        data = x;
        npx = NULL;
    }
};

Utility function to get XOR of two Struct Node pointer
use this function to get XOR of two pointers
struct Node* XOR (struct Node *a, struct Node *b)
{
    return (struct Node*) ((uintptr_t) (a) ^ (uintptr_t) (b));
}
*/

// function should insert the data to the front of the list
Node* insert(Node* head, int data) {
    Node* newNode = new Node(data);  
    newNode->npx = XOR(nullptr, head);

    if (head != nullptr) {
        Node* next = XOR(nullptr, head->npx);
        head->npx = XOR(newNode, next);
    }

    return newNode;  
}

vector<int> getList(Node* head) {
    vector<int> result;
    Node* curr = head;
    Node* prev = nullptr;
    Node* next;

    while (curr != nullptr) {
        result.push_back(curr->data);
        next = XOR(prev, curr->npx);
        prev = curr;
        curr = next;
    }

    return result;
}
