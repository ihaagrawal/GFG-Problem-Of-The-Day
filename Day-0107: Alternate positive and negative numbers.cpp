// Alternate positive and negative numbers (EASY)
// https://www.geeksforgeeks.org/problems/array-of-alternate-ve-and-ve-nos1401/1

class Solution {
  public:

    void rearrange(vector<int> &arr) {
        int n = arr.size();
        vector<int> neg, pos;
        for(int i=0;i<n;i++){
            if(arr[i] < 0) neg.push_back(arr[i]);
            else pos.push_back(arr[i]);
        }
        
        int ind1 = 0, ind2 = 0, i = 0;
        for(int i = 0; i < n; i++) {
            if(i % 2 == 0) {  
                if(ind1 < pos.size()) arr[i] = pos[ind1++];
                else arr[i] = neg[ind2++];  
            } else { 
                if(ind2 < neg.size()) arr[i] = neg[ind2++];
                else arr[i] = pos[ind1++]; 
            }
        }
        
    }
};
