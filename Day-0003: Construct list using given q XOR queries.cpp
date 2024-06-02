// Construct list using given q XOR queries (MEDIUM)
// https://www.geeksforgeeks.org/problems/construct-list-using-given-q-xor-queries/1


class Solution {
  public:
    vector<int> constructList(int q, vector<vector<int>> &queries) {
        vector<int> result;
        result.push_back(0);
        int xr = 0;
        for(auto it : queries){
            if(it[0] == 0) result.push_back(xr ^ it[1]);
            else xr ^= it[1];
        }
        
        for(auto& it : result) it ^= xr; 
        sort(result.begin(), result.end());
        return result;
    }
};
