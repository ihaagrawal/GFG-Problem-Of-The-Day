// Activity Selection (MEDIUM)
// https://www.geeksforgeeks.org/problems/activity-selection-1587115620/1

class Solution {
    public:
    
    static bool comp(pair<int,int>& a, pair<int,int>& b){
        return a.second < b.second;
    }
    
    int activitySelection(vector<int> start, vector<int> end){
        int n = start.size();
       vector<pair<int,int>> jobs(n);
       for(int i=0;i<n;i++){
           jobs[i].first = start[i];
           jobs[i].second = end[i];
       }
       
       sort(jobs.begin(), jobs.end(), comp);
       
       int lastEndTime = -1;
       int maxNumOfActivities = 0;
       for(auto it : jobs){
            if(it.first > lastEndTime){
                maxNumOfActivities++;
                lastEndTime = it.second;
            }
        }
        
        return maxNumOfActivities;
    }
};
