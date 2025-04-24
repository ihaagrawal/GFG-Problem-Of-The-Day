// Unique Number III (MEDIUM)
// https://www.geeksforgeeks.org/problems/find-element-occuring-once-when-all-other-are-present-thrice/1

class Solution {
  public:
    int getSingle(vector<int> &arr) {
        int result = 0;
        
        for (int i = 0; i < 32; ++i) {
            int bitSum = 0;
            
            for (int num : arr) {
                if (num & (1 << i)) {
                    bitSum++;
                }
            }
            
            if (bitSum % 3 != 0) {
                result |= (1 << i);
            }
        }
        
        return result;
    }
};
