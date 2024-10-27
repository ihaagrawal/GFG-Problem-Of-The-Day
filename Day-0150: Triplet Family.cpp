// Triplet Family (BASIC)
// https://www.geeksforgeeks.org/problems/triplet-family/1


class Solution {
  public:
    bool findTriplet(vector<int>& arr) {
        int n = arr.size();
        sort(arr.begin(),arr.end());
        for(int i=0;i<n;i++){
            int j = 0;
            int k = i;
            while(j<k){
                if(arr[j]+arr[k] == arr[i]) return true;
                else if(arr[j]+arr[k] > arr[i]) k--;
                else j++;
            }
        }
        return false;
    }
};
