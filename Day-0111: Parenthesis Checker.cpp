// Parenthesis Checker (EASY)
// https://www.geeksforgeeks.org/problems/parenthesis-checker2744/1

class Solution
{
    public:
    //Function to check if brackets are balanced or not.
    bool ispar(string x){
        stack<char> st;
        
        for (char c : x) {
            if (c == '[' || c == '(' || c == '{') {
                st.push(c);
            } else {
                if (st.empty()) return false;
                
                if ((c == ']' && st.top() != '[') || 
                    (c == '}' && st.top() != '{') || 
                    (c == ')' && st.top() != '(')) {
                    return false;
                }
                
                st.pop();
            }
        }
        
        return st.empty();
    }

};
