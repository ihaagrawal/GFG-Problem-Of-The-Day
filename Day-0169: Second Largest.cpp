// Second Largest (EASY)
// https://www.geeksforgeeks.org/problems/second-largest3735/1

class Solution {
  public:
    // Function returns the second
    // largest elements
    int getSecondLargest(vector<int> &arr) {
        int n = arr.size(), maxi = -1, maxi2 = -1;
        
        for(int i=0;i<n;i++){
            if(arr[i] > maxi){
                maxi2 = maxi;
                maxi = arr[i];
            }else if(arr[i] < maxi && arr[i] > maxi2) maxi2 = arr[i];
        }
        
        return maxi2;
    }
};
