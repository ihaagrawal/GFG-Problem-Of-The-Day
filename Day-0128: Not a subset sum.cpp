// Not a subset sum (MEDIUM)
// https://www.geeksforgeeks.org/problems/smallest-number-subset1220/1


class Solution {
  public:
    long long findSmallest(vector<int> &arr) {
        long long result = 1;
        for(int num : arr){
            if(num > result) break;
            else result += num;
        }
        return result;
    }
};
