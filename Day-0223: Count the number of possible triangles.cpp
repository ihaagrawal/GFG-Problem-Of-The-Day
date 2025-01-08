// Count the number of possible triangles (MEDIUM)
// https://www.geeksforgeeks.org/problems/count-possible-triangles-1587115620/1


class Solution {
  public:
    // Function to count the number of possible triangles.
    int countTriangles(vector<int>& arr) {
        int n = arr.size(), count = 0;
        sort(arr.begin(), arr.end());
        
        for(int i=0;i<n-2;i++){
            for(int j=i+1;j<n-1;j++){
                for(int k=j+1;k<n;k++){
                    if(arr[i] + arr[j] > arr[k]) count++;
                    else break;
                }
            }
        }
        
        return count;
    }
};
