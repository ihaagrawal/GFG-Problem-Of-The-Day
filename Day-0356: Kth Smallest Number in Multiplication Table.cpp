// Kth Smallest Number in Multiplication Table (HARD)
// https://www.geeksforgeeks.org/problems/kth-smallest-number-in-multiplication-table/1

class Solution {
public:
    int countLessEqual(int mid, int r, int c) {
        int col = 0, row = r - 1, count = 0;

        while (col < c && row >= 0) {
            if ((row + 1) * (col + 1) <= mid) {
                count += row + 1;
                col++;
            } else row--;
        }
        return count;
    }
    
    int kthSmallest(int r, int c, int k) {
        int low = 1, high = r * c;

        while (low < high) {
            int mid = (low + high) / 2;
            if (countLessEqual(mid, r, c) < k) low = mid + 1;
            else high = mid;
        }
        return low;
    }
};
