// Index of an Extra Element (EASY)
// https://www.geeksforgeeks.org/problems/index-of-an-extra-element/1

class Solution {
  public:
    int findExtra(int n, int arr1[], int arr2[]) {
        for(int i=0;i<n;i++){
            if(i == n-1 || arr1[i] != arr2[i]) return i;
        }
        return -1;
    }
};
