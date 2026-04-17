class Solution {
   public:
    int mostBooked(int n, vector<vector<int>>& meetings) {
        int size = meetings.size();
        priority_queue<long long, vector<long long>, greater<>> availableRooms;
        priority_queue<pair<long long, long long>, vector<pair<long long, long long>>, greater<>> busy;
        vector<int> rooms(n, 0);

        // sort it by start time 
        sort(meetings.begin(), meetings.end());

        for (int i = 0; i < n; i++) availableRooms.push(i);

        for (vector<int>& meeting : meetings) {
            long long start = meeting[0];
            long long end = meeting[1];
            long long dur = end - start;

            // if busy not empty and next meeting is greater then there is no overlap so free the room
            while (!busy.empty() && busy.top().first <= start) {
                availableRooms.push(busy.top().second);
                busy.pop();
            }

            // if room availble just assign it
            if (!availableRooms.empty()) {
                long long room = availableRooms.top();
                availableRooms.pop();

                busy.push({end, room});
                rooms[room]++;
            } 

            // if no avaiablility then just delay it by closer end busy meeting 
            else {
                auto [freeEnd, r] = busy.top();
                busy.pop();

                long long newEnd = freeEnd + dur;
                busy.push({newEnd, r});
                rooms[r]++;
            }
        }

        // return the min room of max meeting held
        return max_element(rooms.begin(), rooms.end()) - rooms.begin();
    }
};