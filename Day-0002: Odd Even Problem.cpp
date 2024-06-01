Odd Even Problem (EASY)
https://www.geeksforgeeks.org/problems/help-nobita0532/

class Solution {
  public:
    string oddEven(string s) {
        int n = s.length();
        if(n==0) return "";
        int x = 0, y = 0;
        
        map<char,int> mp;
        for(int i=0;i<n;i++) mp[s[i]]++;
        
        for(auto it = mp.begin(); it != mp.end(); ++it) {
            char c = it->first;
            int freq = it->second;
            if((c - 'a' + 1) % 2 == 0) { 
                if(freq % 2 == 0) x++;
            } else { 
                if(freq % 2 != 0) y++;
            }
        }

        
        if((x+y)%2==0) return "EVEN";
        return "ODD";
    }
};
