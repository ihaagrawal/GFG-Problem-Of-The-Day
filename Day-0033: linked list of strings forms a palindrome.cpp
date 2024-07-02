// Linked list of strings forms a palindrome (EASY)
// https://www.geeksforgeeks.org/problems/linked-list-of-strings-forms-a-palindrome/1


struct Node
{
    string data;
    Node* next;

    Node(int x){
        data = x;
        next = NULL;
    }
};
*/
class Solution {
  public:
    bool compute(Node* head) {
        string str = "";
        while(head){
            str += head->data;
            head = head->next;
        }
        
        int left = 0, right = str.length() - 1;
        while(left <= right){
            if(str[left] != str[right]) return false;
            left++;
            right--;
        }
        return true;
    }
};
