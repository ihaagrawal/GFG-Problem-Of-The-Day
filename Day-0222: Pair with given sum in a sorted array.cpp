// Pair with given sum in a sorted array (EASY)
// https://www.geeksforgeeks.org/problems/pair-with-given-sum-in-a-sorted-array4940/1


class Solution {
  public:
    int countPairs(vector<int> &arr, int target) {
        int pairCount = 0;
        int size = arr.size();
        int left = 0, right = size - 1;
        
        while (left < right) {
            if (arr[left] + arr[right] == target) {
                int leftCount = 0, rightCount = 0;
                int leftValue = arr[left], rightValue = arr[right];
                
                while (left <= right && arr[left] == leftValue) {
                    leftCount++;
                    left++;
                }
                while (left <= right && arr[right] == rightValue) {
                    rightCount++;
                    right--;
                }
                
                if (leftValue == rightValue) pairCount += (leftCount * (leftCount - 1)) / 2;
                else pairCount += (leftCount * rightCount);
            } else if (arr[left] + arr[right] > target) right--;
            else left++;
        }
        
        return pairCount;

    }
};
