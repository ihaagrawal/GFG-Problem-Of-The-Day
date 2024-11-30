// Anagram (EASY)
// https://www.geeksforgeeks.org/problems/anagram-1587115620/1


class Solution {
  public:
    // Function is to check whether two strings are anagram of each other or not.
    bool areAnagrams(string& a, string& b) {
        sort(a.begin(), a.end());
        sort(b.begin(), b.end());
        
        if(a == b) return true;
        return false;
    }
};
