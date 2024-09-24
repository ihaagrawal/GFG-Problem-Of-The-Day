// Smallest window in a string containing all the characters of another string (HARD)
// https://www.geeksforgeeks.org/problems/smallest-window-in-a-string-containing-all-the-characters-of-another-string-1587115621/1


class Solution
{
    public:
    //Function to find the smallest window in the string s consisting
    //of all the characters of string p.
    string smallestWindow (string s, string p){
        vector<int> targetFreq(26), windowFreq(26);

        for (auto &ch : p)
            targetFreq[ch - 'a']++;
        
        auto isWindowValid = [&]() -> bool {
            for (int i = 0; i < 26; i++) {
                if (targetFreq[i] > windowFreq[i])
                    return false;
            }
            return true;
        };
        
        int left = 0, sLength = s.length(), minLength = sLength + 2, minStart = -1;
        
        for (int right = 0; right < sLength; right++) {
            windowFreq[s[right] - 'a']++;
            
            while (left <= right && isWindowValid()) {
                int currentLength = right - left + 1;
                if (currentLength < minLength) {
                    minLength = currentLength;
                    minStart = right - minLength + 1;
                }
                windowFreq[s[left++] - 'a']--;
            }
        }
        
        if (minStart == -1)
            return "-1";
        
        return s.substr(minStart, minLength);

        
    }
};
