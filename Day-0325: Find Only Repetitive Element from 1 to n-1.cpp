// Find Only Repetitive Element from 1 to n-1 (EASY)
// https://www.geeksforgeeks.org/problems/find-repetitive-element-from-1-to-n-1/1

class Solution {
  public:
    int findDuplicate(vector<int>& arr) {
        int slow = arr[0];
        int fast = arr[0];
    
        do {
            slow = arr[slow];
            fast = arr[arr[fast]];
        } while (slow != fast);
    
        slow = arr[0];
        while (slow != fast) {
            slow = arr[slow];
            fast = arr[fast];
        }
    
        return slow;
        
    }
};
