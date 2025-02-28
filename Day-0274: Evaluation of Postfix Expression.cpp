// Evaluation of Postfix Expression (MEDIUM)
// https://www.geeksforgeeks.org/problems/evaluation-of-postfix-expression1735/1

class Solution {
  public:
    int evaluate(vector<string>& arr) {
        stack<int> stk;

        for (const string& token : arr) {
            if (token == "+" || token == "-" || token == "*" || token == "/") {
                // Pop the top two elements
                int b = stk.top(); stk.pop();
                int a = stk.top(); stk.pop();
    
                // Perform the operation
                if (token == "+") stk.push(a + b);
                else if (token == "-") stk.push(a - b);
                else if (token == "*") stk.push(a * b);
                else if (token == "/") stk.push(a / b); // Integer division
            } else {
                // Push the number onto the stack
                stk.push(stoi(token));
            }
        }
    
        // The result is the last remaining element in the stack
        return stk.top();
    }
};
