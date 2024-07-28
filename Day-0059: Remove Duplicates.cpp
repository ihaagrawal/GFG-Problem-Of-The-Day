// Remove Duplicates (EASY)
// https://www.geeksforgeeks.org/problems/remove-duplicates3034/1


class Solution {
  public:

    string removeDups(string str) {
        string result = "";
        vector<int> visited(26, 0);
        for(int i = 0; i < str.size(); i++){
            if(!visited[str[i] - 'a']){
                result += str[i];
                visited[str[i] - 'a'] = 1;
            }
        }
        return result;
    }
};
