// Max sum path in two arrays (MEDIUM)
// https://www.geeksforgeeks.org/problems/max-sum-path-in-two-arrays/1


class Solution {
  public:
    int maxPathSum(vector<int> &arr1, vector<int> &arr2) {
        int n = arr1.size(), m = arr2.size();
        int i = 0, j = 0, sum1 = 0, sum2 = 0, result = 0;
        
        while(i < n && j < m){
            if(arr1[i] < arr2[j]){
                sum1 += arr1[i];
                i++;
            }else if(arr1[i] > arr2[j]){
                sum2 += arr2[j];
                j++;
            }else{
                result += max(sum1, sum2);
                result += arr1[i];
                sum1 = 0, sum2 = 0;
                i++;
                j++;
            }
        }
        
        while(i < n) sum1 += arr1[i++];
        while(j < m) sum2 += arr2[j++];
        
        result += max(sum1, sum2);
        return result;
    }
};