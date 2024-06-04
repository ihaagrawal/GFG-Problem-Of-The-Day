// Binary representation of next number (EASY)
// https://www.geeksforgeeks.org/problems/binary-representation-of-next-number3648/1

class Solution {
  public:
    string binaryNextNumber(string s) {
        int n=s.size();
        int carry=1;
        int j=0;
         while (j < n && s[j] == '0') {
            s.erase(s.begin() + j);
        }
        for(int i=n-1;i>=0;i--){
            if(s[i]=='0'){
                s[i]='1';
                carry=0;
                
            }
            else if(s[i]=='1'){
                s[i]='0';
                carry=1;
            }
            if(carry==0)
              break;
              
        }
        if(carry)
          s='1'+s;
        
        return s;
    }
};
