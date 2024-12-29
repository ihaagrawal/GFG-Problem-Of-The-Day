// Intersection of Two arrays with Duplicate Elements (EASY)
// https://www.geeksforgeeks.org/problems/intersection-of-two-arrays-with-duplicate-elements/1


class Solution {
  public:
    vector<int> intersectionWithDuplicates(vector<int>& a, vector<int>& b) {
        unordered_set<int> setA(a.begin(), a.end());
        unordered_set<int> result;
        for (int num : b) {
            if (setA.count(num)) {
                result.insert(num);
            }
        }
        return vector<int>(result.begin(), result.end());
    }
};
