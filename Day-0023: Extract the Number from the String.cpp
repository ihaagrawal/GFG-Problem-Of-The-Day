// Extract the Number from the String (EASY)
// https://www.geeksforgeeks.org/problems/extract-the-number-from-the-string3428/1


class Solution {
  public:
    long long ExtractNumber(string sentence) {
        stringstream ss(sentence);
        string temp = "";
        long long ans = -1;
        while(ss >> temp){
            if(isdigit(temp[0])){
                if((temp.find('9') == string::npos)){
                    ans = max(ans, stoll(temp));
                }
            }
        }
        return ans;
    }
};
