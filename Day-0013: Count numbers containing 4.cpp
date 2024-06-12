// Count numbers containing 4 (EASY)
// https://www.geeksforgeeks.org/problems/count-numbers-containing-43022/1

class Solution {
  public:
    int countNumberswith4(int n) {
        int count = 0;
        for(int i=1;i<=n;i++){
            string str = to_string(i);
            for(int j=0;j<str.length();j++){
                if(str[j]=='4'){
                    count++;
                    break;
                }
            }
        }
        return count;
    }
};
