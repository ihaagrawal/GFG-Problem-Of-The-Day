// Unique Number I (EASY)
// https://www.geeksforgeeks.org/problems/find-unique-number/1

class Solution {
  public:
    int findUnique(vector<int> &arr) {
        int unique = 0;
        for (int num : arr) unique ^= num;  
        return unique;
    }
};
