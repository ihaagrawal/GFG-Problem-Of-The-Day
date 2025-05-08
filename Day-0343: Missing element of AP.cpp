// Missing element of AP (MEDIUM)
// https://www.geeksforgeeks.org/problems/missing-element-of-ap2228/1

class Solution {
  public:
    int findMissing(vector<int> &arr) {
        int d=arr[1]-arr[0];
        for(int i=1;i<arr.size();i++){
            if(arr[i]-arr[i-1]!=d){
                return arr[i-1]+d;
            }
        }
        
        return arr[arr.size()-1]+d;
    }
};
