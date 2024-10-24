// Modify the Array (EASY)
// https://www.geeksforgeeks.org/problems/ease-the-array0633/1


class Solution {
  public:
    vector<int> modifyAndRearrangeArray(vector<int> &arr) {
        int n = arr.size();
        for(int i=0;i<n-1;i++){
            if(arr[i] == arr[i+1]){
                arr[i] = arr[i] * 2;
                arr[i+1] = 0;
            }
        }
        
        vector<int> result(n, 0);
        int j = 0;
        for(int num : arr){
            if(num != 0){
                result[j] = num;
                j++;
            }
        }
        
        return result;
    }
};
