// Sum Pair closest to target (EASY)
// https://www.geeksforgeeks.org/problems/pair-in-array-whose-sum-is-closest-to-x1124/1


class Solution {
  public:
    vector<int> sumClosest(vector<int>& arr, int target) {
        int n = arr.size();
        if (n < 2) return {};

        sort(arr.begin(), arr.end());

        int lastDiff = INT_MAX;
        int maxAbsDiff = 0;
        int a = 0, b = 0;

        int i = 0, j = n - 1;

        while (i < j) {
            int sum = arr[i] + arr[j];
            int diff = abs(target - sum);
            int absDiff = abs(arr[i] - arr[j]);

            if (diff < lastDiff || (diff == lastDiff && absDiff > maxAbsDiff)) {
                lastDiff = diff;
                maxAbsDiff = absDiff;
                a = arr[i];
                b = arr[j];
            }

            if (sum < target) i++;
            else j--;
        }

        return {a, b};
    }
};
