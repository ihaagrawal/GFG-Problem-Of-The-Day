// Meeting Rooms III (HARD)
// https://www.geeksforgeeks.org/problems/meeting-rooms-iii/1

class Solution {
  public:
    int mostBooked(int n, vector<vector<int>> &meetings) {
        sort(meetings.begin(), meetings.end());
        priority_queue<int, vector<int>, greater<int>> availableRooms;
        priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> busyRooms;
        vector<int> meetingCounts(n, 0);
    
        for (int i = 0; i < n; ++i) {
            availableRooms.push(i);
        }
    
        for (const auto &meeting : meetings) {
            long long start = meeting[0], end = meeting[1];
    
            while (!busyRooms.empty() && busyRooms.top().first <= start) {
                availableRooms.push(busyRooms.top().second);
                busyRooms.pop();
            }
    
            if (!availableRooms.empty()) {
                int room = availableRooms.top();
                availableRooms.pop();
                meetingCounts[room]++;
                busyRooms.push({end, room});
            } else {
                auto top = busyRooms.top();
                busyRooms.pop();
                int room = top.second;
                long long availableTime = top.first;
                meetingCounts[room]++;
                busyRooms.push({availableTime + (end - start), room});
            }
        }
    
        int maxMeetings = 0, bestRoom = 0;
        for (int i = 0; i < n; ++i) {
            if (meetingCounts[i] > maxMeetings || (meetingCounts[i] == maxMeetings && i < bestRoom)) {
                maxMeetings = meetingCounts[i];
                bestRoom = i;
            }
        }
    
        return bestRoom;
        
    }
};
