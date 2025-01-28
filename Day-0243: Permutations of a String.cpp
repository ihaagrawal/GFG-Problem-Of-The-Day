// Permutations of a String (MEDIUM)
// https://www.geeksforgeeks.org/problems/permutations-of-a-given-string2041/1

class Solution {
  public:
    vector<string> findPermutation(string &s) {
        vector<string> result;
        string current;
        vector<bool> visited(s.size(), false);
        sort(s.begin(), s.end());
        
        function<void()> backtrack = [&]() {
            if (current.size() == s.size()) {
                result.push_back(current);
                return;
            }
            for (int i = 0; i < s.size(); ++i) {
                if (visited[i]) continue;
                if (i > 0 && s[i] == s[i - 1] && !visited[i - 1]) continue;
                visited[i] = true;
                current.push_back(s[i]);
                backtrack();
                current.pop_back();
                visited[i] = false;
            }
        };
        
        backtrack();
        return result;
    }
};
