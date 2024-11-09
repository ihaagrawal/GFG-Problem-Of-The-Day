// Minimum sum (MEDIUM)
// https://www.geeksforgeeks.org/problems/minimum-sum4058/1


class Solution {
  public:
    string minSum(vector<int> &arr) {
        sort(arr.begin(), arr.end());

        string num1, num2;
        int n = arr.size();
        
        for (int i = 0; i < n; i++) {
            if (i % 2 == 0) {
                num1 += to_string(arr[i]);
            } else {
                num2 += to_string(arr[i]);
            }
        }
    
        int carry = 0;
        int index1 = num1.size() - 1;
        int index2 = num2.size() - 1;
        string result = "";
    
        while (index1 >= 0 || index2 >= 0 || carry > 0) {
            int sum = carry;
            if (index1 >= 0) {
                sum += num1[index1] - '0';
                index1--;
            }
            if (index2 >= 0) {
                sum += num2[index2] - '0';
                index2--;
            }
            result += (sum % 10) + '0';
            carry = sum / 10;
        }
        
        reverse(result.begin(), result.end());
        
        int leadingZeroIndex = 0;
        while (result[leadingZeroIndex] == '0') {
            leadingZeroIndex++;
        }
        
        if (result[0] == '0') {
            return result.substr(leadingZeroIndex, result.length() - leadingZeroIndex);
        }
        
        return result;
    }
};
