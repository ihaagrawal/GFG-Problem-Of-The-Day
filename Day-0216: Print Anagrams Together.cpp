// Print Anagrams Together (MEDIUM)
// https://www.geeksforgeeks.org/problems/print-anagrams-together/1

class Solution {
  public:
    vector<vector<string>> anagrams(vector<string>& arr) {
        unordered_map<string, vector<string>> anagramMap;
        vector<vector<string>> result;
        
        for (auto& word : arr) {
            string sortedWord = word;
            sort(sortedWord.begin(), sortedWord.end());
            anagramMap[sortedWord].push_back(word);
        }
        
        for (auto& entry : anagramMap) {
            result.push_back(entry.second);
        }
        
        sort(result.begin(), result.end());
        return result;
    }
};
