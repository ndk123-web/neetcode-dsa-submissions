class Solution {
   public:
    int mostBooked(int n, vector<vector<int>>& meetings) {
        sort(meetings.begin(), meetings.end());

        // available rooms (smallest index first)
        priority_queue<int, vector<int>, greater<>> available;

        // busy rooms: {endTime, room}
        priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<>> busy;

        vector<int> count(n, 0);

        for (int i = 0; i < n; i++) {
            available.push(i);
        }

        for (auto& meeting : meetings) {
            long long start = meeting[0];
            long long end = meeting[1];
            long long duration = end - start;

            // free all rooms that are done
            while (!busy.empty() && busy.top().first <= start) {
                available.push(busy.top().second);
                busy.pop();
            }

            if (!available.empty()) {
                // assign directly
                int room = available.top();
                available.pop();

                busy.push({end, room});
                count[room]++;
            } else {
                // delay meeting
                auto [freeTime, room] = busy.top();
                busy.pop();

                long long newEnd = freeTime + duration;
                busy.push({newEnd, room});
                count[room]++;
            }
        }

        // find room with max meetings
        int ans = 0;
        for (int i = 1; i < n; i++) {
            if (count[i] > count[ans]) {
                ans = i;
            }
        }

        return ans;
    }
};