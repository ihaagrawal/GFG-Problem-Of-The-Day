// Add Binary Strings (MEDIUM)
// https://www.geeksforgeeks.org/problems/add-binary-strings3805/1


class Solution {
  public:
    string addBinary(string& a, string& b) {
        string res = "";
        int p1 = a.size() - 1;
        int p2 = b.size() - 1;
        int c = 0;
    
        while (p1 >= 0 || p2 >= 0 || c > 0) {
            int sum = c;
            if (p1 >= 0 && a[p1] == '1') sum++;
            if (p2 >= 0 && b[p2] == '1') sum++;
            res += (sum % 2 == 0 ? '0' : '1');
            c = sum / 2;
            p1--;
            p2--;
        }
    
        reverse(res.begin(), res.end());
        int i = 0;
        while (res[i] == '0') {
            res.erase(0, 1);
        }
        return res;
    }
};
