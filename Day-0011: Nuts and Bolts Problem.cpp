// Nuts and Bolts Problem (MEDIUM)
// https://www.geeksforgeeks.org/problems/nuts-and-bolts-problem0431/1

class Solution {
  public:

    void matchPairs(int n, char nuts[], char bolts[]) {
        unordered_map<char,int> mp;
        mp['^']=1; mp['@']=2;
        mp['?']=3; mp['*']=4;
        mp['&']=5; mp['%']=6;
        mp['$']=7; mp['#']=8;
        mp['!']=9;
        
        priority_queue<pair<int,char>> pq;
        for(int i=0; i<n; i++){
            pq.push({mp[nuts[i]],nuts[i]});
        }
        for(int i=0; i<n; i++){
            nuts[i]=bolts[i]=pq.top().second;
            pq.pop();
        }
    }
};
