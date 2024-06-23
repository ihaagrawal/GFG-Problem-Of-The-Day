// Print Bracket Number (EASY)
// https://www.geeksforgeeks.org/problems/print-bracket-number4058/1

class Solution {
  public:

    vector<int> bracketNumbers(string str) {
        vector<int> list;
        stack<int> st;
        unordered_map<int,int> mp;
        int count=1;
        for(int i=0;i<str.size();i++){
            if(str[i]=='('){
                st.push(count);
                mp[i] = count;
                count++;
            }
            else if(str[i]==')'){
                if(!st.empty()){
                    int l = st.top();
                    st.pop();
                    mp[i] = l;
                }
                
            }
        }
        
        for(int i=0;i<str.size();i++){
            if(str[i]=='('||str[i]==')'){
                list.push_back(mp[i]);
                
            }
        }
        
        return list;
    }
};
