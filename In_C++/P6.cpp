class Solution {
public:
    int mostBooked(int n, vector<vector<int>>& meetings) {
        // Sort meetings by start time
        sort(meetings.begin(), meetings.end());

        // Min-heap for free rooms (smallest number first)
        priority_queue<int, vector<int>, greater<int>> freeRooms;

        // Min-heap for busy rooms: {end_time, room_number}
        priority_queue<pair<long long, int>, 
                       vector<pair<long long, int>>, 
                       greater<pair<long long, int>>> busy;

        // Initially all rooms are free
        for (int i = 0; i < n; i++) {
            freeRooms.push(i);
        }

        vector<long long> count(n, 0); // number of meetings held by each room

        for (auto& m : meetings) {
            long long start = m[0];
            long long end = m[1];
            long long duration = end - start;

            // Free all rooms whose meeting ended before current start
            while (!busy.empty() && busy.top().first <= start) {
                freeRooms.push(busy.top().second);
                busy.pop();
            }

            if (!freeRooms.empty()) {
                // Use the smallest available room
                int room = freeRooms.top();
                freeRooms.pop();

                busy.push({end, room});
                count[room]++;
            } else {
                // No room is available -> delay the meeting
                auto [end_time, room] = busy.top();
                busy.pop();

                long long new_start = end_time;
                long long new_end = new_start + duration;

                busy.push({new_end, room});
                count[room]++;
            }
        }

        // Find the room with max meetings
        long long maxMeet = -1, ansRoom = 0;
        for (int i = 0; i < n; i++) {
            if (count[i] > maxMeet) {
                maxMeet = count[i];
                ansRoom = i;
            }
        }
        return ansRoom;
    }
};
