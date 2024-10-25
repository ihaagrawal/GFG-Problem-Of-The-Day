// Alternative Sorting (BASIC)
// https://www.geeksforgeeks.org/problems/alternative-sorting1311/1


class Solution {

  public:
    vector<int> alternateSort(vector<int>& arr) {
        int n = arr.size();
        vector<int> result;
        sort(arr.begin(), arr.end());
        
        int i = 0, j = n-1;
        while(i <= j){
            result.push_back(arr[j]);
            if(i == j) break;
            result.push_back(arr[i]);
            i++;
            j--;
        }
        
        return result;
    }
};
