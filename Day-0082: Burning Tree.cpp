// Burning Tree (HARD)
// https://www.geeksforgeeks.org/problems/burning-tree/1

/*
struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/
class Solution {
  public:
  
    int solve(Node* root, int& timi, int& target){
        if(!root) return 0;
        
        int num1 = solve(root->left, timi, target);
        int num2 = solve(root->right, timi, target);
        
        if(root->data == target){
            timi = max(timi, max(num1, num2));
            return -1; 
        }else{
            if(num1 >= 0 && num2 >= 0) return max(num1, num2)+1;
            if(num1 > num2) swap(num1, num2);
            timi = max(timi, num2 - num1);
            return num1-1;
        }
    }
  
    int minTime(Node* root, int target){
        int timi = 0;
        solve(root, timi, target);
        return timi;
    }
};
