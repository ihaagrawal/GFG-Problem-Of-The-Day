// Alien Dictionary (HARD)
// https://www.geeksforgeeks.org/problems/alien-dictionary/1

class Solution {
  public:
    string findOrder(vector<string> &words) {
        unordered_map<char, unordered_set<char>> graph;
        unordered_map<char, int> inDegree;
        unordered_set<char> allChars;
        
        for (const string& word : words) {
            for (char ch : word) {
                inDegree[ch] = 0;
                allChars.insert(ch);
            }
        }
        
        for (size_t i = 0; i < words.size() - 1; ++i) {
            string word1 = words[i];
            string word2 = words[i + 1];
            size_t minLength = min(word1.size(), word2.size());
            bool foundOrder = false;
    
            for (size_t j = 0; j < minLength; ++j) {
                if (word1[j] != word2[j]) {
                    if (graph[word1[j]].insert(word2[j]).second) {
                        ++inDegree[word2[j]];
                    }
                    foundOrder = true;
                    break;
                }
            }
    
            if (!foundOrder && word1.size() > word2.size()) {
                return "";
            }
        }
        
        queue<char> zeroInDegree;
        for (auto& entry : inDegree) {
            if (entry.second == 0) {
                zeroInDegree.push(entry.first);
            }
        }
        
        string result;
        while (!zeroInDegree.empty()) {
            char current = zeroInDegree.front();
            zeroInDegree.pop();
            result += current;
    
            for (char neighbor : graph[current]) {
                --inDegree[neighbor];
                if (inDegree[neighbor] == 0) {
                    zeroInDegree.push(neighbor);
                }
            }
        }
        
        if (result.size() != allChars.size()) {
            return "";
        }
        
        return result;
        
    }
};
