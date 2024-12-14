// Search in Rotated Sorted Array (MEDIUM)
// https://www.geeksforgeeks.org/problems/search-in-a-rotated-array4618/1


class Solution {
  public:
    int search(vector<int>& arr, int key) {
        int n = arr.size();
        int low = 0, high = n-1;
        
        while(low <= high){
            int mid = low + (high - low)/2;
            if(arr[mid] == key) return mid;
            else if(arr[mid] >= arr[low]){
                if(key < arr[mid] && key >= arr[low]) high = mid - 1;
                else low = mid + 1;
            }else{
                if(key > arr[mid] && key <= arr[high]) low = mid + 1;
                else high = mid - 1;
            }
        }
        
        return -1;
    }
};
