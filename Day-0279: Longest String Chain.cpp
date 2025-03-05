// Longest String Chain (MEDIUM)
// https://www.geeksforgeeks.org/problems/longest-string-chain/1


class Solution {
  public:
    int longestStringChain(vector<string>& w) {
        sort(w.begin(), w.end(), [](const string& a, const string& b) {
            return a.size() < b.size();
        });

        unordered_map<string, int> dp;
        int res = 1;

        for (const string& s : w) {
            dp[s] = 1;
            for (int i = 0; i < s.size(); ++i) {
                string p = s.substr(0, i) + s.substr(i + 1);
                if (dp.find(p) != dp.end()) {
                    dp[s] = max(dp[s], dp[p] + 1);
                }
            }
            res = max(res, dp[s]);
        }

        return res;
    }
};
