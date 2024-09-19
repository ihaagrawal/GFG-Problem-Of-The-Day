// Reverse Words (EASY)
// https://www.geeksforgeeks.org/problems/reverse-words-in-a-given-string5459/1


class Solution {
  public:
    // Function to reverse words in a given string.
    string reverseWords(string str) {
        reverse(str.begin(), str.end());
        
        stringstream ss(str);
        string word;
        string result;
        
        while (getline(ss, word, '.')) {
            reverse(word.begin(), word.end()); 
            
            if (!result.empty()) result += "."; 
            result += word;
        }
        
        return result;
    }
};
