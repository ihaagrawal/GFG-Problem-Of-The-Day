// Prime List (MEDIUM)
// https://www.geeksforgeeks.org/problems/prime-list--170646/1

/*
class Node{
public:
    int val;
    Node *next;
    Node(int num){
        val=num;
        next=NULL;
    }
};
*/

class Solution {
  public:
  
    bool isPrime(int n) {
        if (n <= 1) return false;
        if (n <= 3) return true; // 2 and 3 are prime
        if (n % 2 == 0 || n % 3 == 0) return false;
        for (int i = 5; i * i <= n; i += 6) {
            if (n % i == 0 || n % (i + 2) == 0) return false;
        }
        return true;
    }

    // Function to find the nearest prime for a given number
    int nearestPrime(int n) {
        if (isPrime(n)) return n;

        int lower = n - 1, higher = n + 1;
        while (true) {
            if (lower > 1 && isPrime(lower)) return lower;
            if (isPrime(higher)) return higher;
            lower--;
            higher++;
        }
    }

    // Main function to modify the linked list
    Node* primeList(Node* head) {
        Node* temp = head;
        while (temp) {
            temp->val = nearestPrime(temp->val);
            temp = temp->next;
        }
        return head;
    }
};
