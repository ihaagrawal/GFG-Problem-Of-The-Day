// Rotate and delete (MEDIUM)
// https://www.geeksforgeeks.org/problems/rotate-and-delete-1587115621/1  


class Solution {
  public:
    int rotateDelete(vector<int> &arr) {
        int n = arr.size();
        int k = 1;
        while (n > 1) {
            int last = arr.back();
            arr.pop_back();
            arr.insert(arr.begin(), last);

            if(k > n) arr.erase(arr.begin());
            else arr.erase(arr.begin() + (n-k));
            
            n = arr.size();
            k++;
        }

        return arr[0];
    }
};
