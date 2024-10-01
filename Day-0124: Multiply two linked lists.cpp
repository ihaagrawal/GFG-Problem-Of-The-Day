// Multiply two linked lists (EASY)
// https://www.geeksforgeeks.org/problems/multiply-two-linked-lists/1

class solution {
  public:
    long long mod = 1e9 + 7;

    long long multiplyTwoLists(Node *list1, Node *list2) {
        long long num1 = 0, num2 = 0;
    
        Node* currentNode = list1;
        while(currentNode != NULL) {
            num1 = (num1 * 10 + currentNode->data) % mod;
            currentNode = currentNode->next;
        }
    
        currentNode = list2;
        while(currentNode != NULL) {
            num2 = (num2 * 10 + currentNode->data) % mod;
            currentNode = currentNode->next;
        }
    
        return (num1 * num2) % mod;
    }

};
