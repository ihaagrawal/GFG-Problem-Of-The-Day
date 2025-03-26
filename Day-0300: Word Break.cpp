// Word Break (MEDIUM)
// https://www.geeksforgeeks.org/problems/word-break1352/1

class Solution {
  public:
    bool wordBreak(string &s, vector<string> &dic) {
        int n = s.size(), m = dic.size();
        vector<int> dp(n + 1, 0);
        dp[n] = 1;
    
        for (int i = n - 1; i >= 0; i--) {
            for (int j = 0; j < m; j++) {
                int k = 0;
                for (int l = i; l < n && k < dic[j].size(); l++) {
                    if (s[l] == dic[j][k]) {
                        k++;
                    } else {
                        break;
                    }
                }
                if (k == dic[j].size()) {
                    dp[i] |= dp[i + k];
                }
            }
        }
    
        return dp[0];
    }
};
