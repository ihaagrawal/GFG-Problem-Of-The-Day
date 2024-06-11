// Maximum Tip Calculator (MEDIUM)
// https://www.geeksforgeeks.org/problems/maximum-tip-calculator2631/1


class Solution {
public:
    static bool comp(const pair<pair<int, int>, int>& a, const pair<pair<int, int>, int>& b) {
        return a.second > b.second;
    }

    long long maxTip(int n, int x, int y, vector<int> &arr, vector<int> &brr) {
        vector<pair<pair<int, int>, int>> vec(n);
        
        for (int i = 0; i < n; i++) {
            vec[i].first.first = arr[i];
            vec[i].first.second = brr[i];
            vec[i].second = abs(arr[i] - brr[i]);
        }
        
        sort(vec.begin(), vec.end(), comp);
        
        long long sum = 0;
        int countA = 0, countB = 0;

        for (auto it : vec) {
            int tipA = it.first.first;
            int tipB = it.first.second;
            if ((tipA >= tipB && countA < x) || countB == y) {
                sum += tipA;
                countA++;
            } else {
                sum += tipB;
                countB++;
            }
        }
        
        return sum;
    }
};
