// Array to BST (EASY)
// https://www.geeksforgeeks.org/problems/array-to-bst4443/1


/*
struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int val)
        : data(val)
        , left(nullptr)
        , right(nullptr) {}
};
*/

class Solution {
  public:
  
    Node* build(vector<int>& nums, int start, int end){
        if(start > end) return nullptr;
        int mid = (start+end)/2;
        
        Node* temp = new Node(nums[mid]);
        temp->left = build(nums, start, mid-1);
        temp->right = build(nums, mid+1, end);
    }
  
    Node* sortedArrayToBST(vector<int>& nums) {
        int end = nums.size()-1, start = 0;
        return build(nums, start, end);
    }
};
