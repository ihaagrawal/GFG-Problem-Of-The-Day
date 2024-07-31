// Longest Common Prefix of Strings (EASY)
// https://www.geeksforgeeks.org/problems/longest-common-prefix-in-an-array5129/1


class Solution {
  public:

    string longestCommonPrefix(vector<string> arr) {
        int n = arr.size();
        sort(arr.begin(), arr.end());
        string first = arr[0], last = arr[n-1];
        
        string result = "";
        for(int i=0;i<first.size();i++){
            if(first[i] == last[i]) result += first[i];
            else break;
        }
        
        if(result == "") return "-1";
        return result;
    }
};
