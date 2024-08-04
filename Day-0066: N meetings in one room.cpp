// N meetings in one room (EASY)
// https://www.geeksforgeeks.org/problems/n-meetings-in-one-room-1587115620/1


class Solution {
  public:
    // Function to find the maximum number of meetings that can
    // be performed in a meeting room.
    
    static bool comp(const pair<int, int>& a, pair<int,int>& b){
        return a.second < b.second;
    }
    
    int maxMeetings(int n, int start[], int end[]) {
        vector<pair<int,int>> arr(n);
        for(int i=0;i<n;i++){
            arr[i].first = start[i];
            arr[i].second = end[i];
        }
        
        sort(arr.begin(), arr.end(), comp);
        
        int count = 0;
        int lastEnd = -1;
        for(auto it : arr){
            if(it.first > lastEnd){
                count++;
                lastEnd = it.second;
            }
        }
        
        return count;
    }
};
