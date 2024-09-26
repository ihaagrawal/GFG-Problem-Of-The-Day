// Roof Top (EASY)
// https://www.geeksforgeeks.org/problems/roof-top-1587115621/1


class Solution {
  public:
    // Function to find maximum number of consecutive steps
    // to gain an increase in altitude with each step.
    int maxStep(vector<int>& arr) {
        int result = 0;
        int count = 0;
        for(int i = 0;i<arr.size()-1;i++){
            if(arr[i]<arr[i+1]) count ++;
            else{
                result = max(result,count);
                count = 0;
            }
        }
        result = max(count,result);
        return result;
    }
};
