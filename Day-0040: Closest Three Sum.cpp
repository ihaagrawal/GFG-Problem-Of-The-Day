// Closest Three Sum (MEDIUM)
// https://www.geeksforgeeks.org/problems/three-sum-closest/1


class Solution {
  public:
    int threeSumClosest(vector<int> arr, int target) {
        int n = arr.size(), prevDiff = INT_MAX, prevSum = 0;
        sort(arr.begin(), arr.end());
        
        for(int i=0;i<n;i++){
            int low = i+1, high = n-1;
            while(low < high){
                int sum = arr[i] + arr[low] + arr[high];
                if(sum == target) return sum;
                else if(sum > target) high--;
                else low++;
                
                int diff = abs(target - sum);
                if(diff < prevDiff){
                    prevDiff = diff;
                    prevSum = sum;
                }else if(diff == prevDiff) prevSum = max(prevSum, sum);   
            }
        }
        
        return prevSum;
    }
};
