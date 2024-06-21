// Compare two fractions (EASY)
// https://www.geeksforgeeks.org/problems/compare-two-fractions4438/1

class Solution {
  public:
  
    vector<string> split(const string &s, char del){
        vector<string> numbers;
        stringstream ss(s);
        string num;
        while(getline(ss, num, del)){
            numbers.push_back(num);
        }
        return numbers;
    }
  
    string compareFrac(string s) {
        vector<string> v = split(s, ',');
        vector<string> a = split(v[0], '/');
        vector<string> b = split(v[1], '/');
        
        int x1 = stoi(a[0]), y1 = stoi(a[1]);
        int x2 = stoi(b[0]), y2 = stoi(b[1]);
        
        int num1 = x1 * y2;
        int num2 = x2 * y1;
        
        if(num1 > num2) return to_string(x1) + "/" + to_string(y1);
        else if(num1 == num2) return "equal";
        else return to_string(x2) + "/" + to_string(y2);
    }
};
