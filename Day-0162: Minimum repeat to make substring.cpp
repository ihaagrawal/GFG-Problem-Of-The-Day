// Minimum repeat to make substring (MEDIUM)
// https://www.geeksforgeeks.org/problems/minimum-times-a-has-to-be-repeated-such-that-b-is-a-substring-of-it--170645/1


class Solution {
  public:
    int minRepeats(string& s1, string& s2) {
        string first = s1;
        int count = 1;
        
        while(s1.size() < s2.size()){
            s1 += first;
            count++;
        }
        
        if(s1.find(s2) != -1) return count;
        
        s1 += first;
        count++;
        if(s1.find(s2) != -1) return count;
        
        return -1;
    }
};
