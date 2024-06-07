// Maximum occured integer (MEDIUM)
// https://www.geeksforgeeks.org/problems/maximum-occured-integer4602/1


class Solution {
  public:
    // l and r are input array
    // maxx : maximum in r[]
    // n: size of array
    // arr[] : declared globally with size equal to maximum in l[] and r[]
    // Function to find the maximum occurred integer in all ranges.
    int maxOccured(int n, int l[], int r[], int maxx) {

       vector<int> arr(maxx + 2, 0);

        for (int i = 0; i < n; ++i) {
            arr[l[i]]++;
            arr[r[i] + 1]--;
        }

        int max_occurrence = INT_MIN;
        int max_occurred_value = 0;
        int current_occurrence = 0;

        for (int i = 0; i <= maxx; ++i) {
            current_occurrence += arr[i];
            if (current_occurrence > max_occurrence) {
                max_occurrence = current_occurrence;
                max_occurred_value = i;
            }
        }

        return max_occurred_value;
    }
};
