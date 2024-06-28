// The Palindrome Pattern (HARD)
// https://www.geeksforgeeks.org/problems/the-palindrome-pattern3900/1

class Solution {
  public:

    bool isPalindrome(vector<int>& sequence) {
        int left = 0;
        int right = sequence.size() - 1;
        while (left < right) {
            if (sequence[left] != sequence[right])
                return false;
            left++;
            right--;
        }
        return true;
    }

    string pattern(vector<vector<int>> &matrix) {
        for (int row = 0; row < matrix.size(); row++) {
            vector<int> rowSequence;
            for (int col = 0; col < matrix[0].size(); col++)
                rowSequence.push_back(matrix[row][col]);
            
            if (isPalindrome(rowSequence))
                return to_string(row) + " R";
        }

        for (int col = 0; col < matrix[0].size(); col++) {
            vector<int> colSequence;
            for (int row = 0; row < matrix.size(); row++)
                colSequence.push_back(matrix[row][col]);
            
            if (isPalindrome(colSequence))
                return to_string(col) + " C";
        }

        return "-1";
    }
};
