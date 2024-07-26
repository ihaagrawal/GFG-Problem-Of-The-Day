// K-Pangrams (EASY)
// https://www.geeksforgeeks.org/problems/k-pangrams0909/1

class Solution {
  public:

    bool kPangram(string str, int k) {
        int n = 0;
        unordered_map<char, int> mp;
        for(int i=0;i<str.length();i++){
            if(str[i] != 32){
                n++;
                mp[str[i]]++;
            }
        }
        
        if(n < 26) return false;
        if(mp.size() == 26) return true;
        if(26 - mp.size() <= k) return true;
        
        return false;
    }
};
