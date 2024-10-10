// Max distance between same elements (EASY)
// https://www.geeksforgeeks.org/problems/max-distance-between-same-elements/1


class Solution {
  public:
    int maxDistance(vector<int> &arr) {
        unordered_map<int, int> first;
        int max_dist = 0;
    
        for (int i = 0; i < arr.size(); i++) {
            if (first.find(arr[i]) != first.end()) {
                int dist = i - first[arr[i]];
                max_dist = max(max_dist, dist);
            } else first[arr[i]] = i;
        }
    
        return max_dist;
    }
};
