// Container With Most Water (MEDIUM)
// https://www.geeksforgeeks.org/problems/container-with-most-water0535/1


class Solution {

  public:
    int maxWater(vector<int> &height) {
        int len = height.size();
        int low=0, high=len-1;
        long long area=0;
        while(low<high){
            long long new_area=min(height[low], height[high])*(high-low);
            area=max(area, new_area);
            if(height[low]<height[high]) low++;
            else high--;
        }
        return area;
    }
};
