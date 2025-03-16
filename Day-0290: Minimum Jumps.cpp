// Minimum Jumps (MEDIUM)
// https://www.geeksforgeeks.org/problems/minimum-number-of-jumps-1587115620/1

class Solution {
  public:
    int minJumps(vector<int>& arr) {
        int n = arr.size();
        int jumps = 0, range = arr[0], pos = 0;
        if(n <= 1) return 0;
        if(arr[0] == 0) return -1;
        
        for(int i=0;i<n;i++){
            range = max(range, i+arr[i]);
            if(pos == i){
                pos = range;
                jumps++;
            }
            
            if(pos >= n-1) return jumps;
        }
        return -1;
    }
};
