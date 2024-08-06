// Validate an IP Address (MEDIUM)
// https://www.geeksforgeeks.org/problems/validate-an-ip-address-1587115621/1

class Solution {
  public:
  
      vector<string> splitString(const string& str, char delimiter) {
        vector<string> tokens;
        string token;
        stringstream ss(str);
    
        while (getline(ss, token, delimiter)) {
            tokens.push_back(token);
        }
    
        return tokens;
    }
  
    int isValid(string str) {
        int n = str.length();
        char delimiter = '.';
        vector<string> tokens = splitString(str, delimiter);
        
        for(string token : tokens){
            int m = token.length();
            if(m > 3) return false;
            int num = stoi(token);
            if(num < 0 || num > 255) return false;
        }
        
        return true;
    }
};
