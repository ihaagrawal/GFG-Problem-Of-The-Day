// Sub-arrays with equal number of occurences (HARD)
// https://www.geeksforgeeks.org/problems/sub-arrays-with-equal-number-of-occurences3901/1


class Solution {
  public:
    int sameOccurrence(vector<int>& arr, int x, int y) {
        unordered_map<int, int> diffCount;
        int diff = 0;
        int result = 0;
        
        diffCount[0] = 1;
    
        for (int i = 0; i < arr.size(); i++) {
            if (arr[i] == x) diff++;
            else if (arr[i] == y) diff--;
            
            if (diffCount.find(diff) != diffCount.end()) result += diffCount[diff];
            diffCount[diff]++;
        }
        
        return result;
    }
};
