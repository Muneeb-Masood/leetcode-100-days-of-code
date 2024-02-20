class Solution {
public:
    int mostBooked(int n, vector<vector<int>>& meetings) {
        sort(meetings.begin(), meetings.end());
        vector<int> meetingCount(n, 0);
        vector<bool> isFree(n, true);
        vector<long long int> meetingFreeTimes(n, 0);
        int maxCount = INT_MIN;
        int maxCountKaINdex;

        for (int i = 0; i < meetings.size(); i++) {
            int minMeetingFreeKaIndex;
            bool found = false;
            if (meetings[i][0] >= *(min_element(meetingFreeTimes.begin(), meetingFreeTimes.end()))) {
                for (int j = 0; j < n; j++) {
                    if (meetingFreeTimes[j] <= meetings[i][0]) {
                        minMeetingFreeKaIndex = j;
                        break;
                    }
                }
                meetingCount[minMeetingFreeKaIndex]++;
                if (meetingFreeTimes[minMeetingFreeKaIndex] == 0 || meetingFreeTimes[minMeetingFreeKaIndex] < meetings[i][0]) {
                    meetingFreeTimes[minMeetingFreeKaIndex] = meetings[i][1];
                } else {
                    meetingFreeTimes[minMeetingFreeKaIndex] += meetings[i][1] - meetings[i][0];
                }
            } else {
                for (int j = 0; j < n; j++) {
                    if (meetingFreeTimes[j] == *(min_element(meetingFreeTimes.begin(), meetingFreeTimes.end()))) {
                        minMeetingFreeKaIndex = j;
                        break;
                    }
                }
                meetingCount[minMeetingFreeKaIndex]++;
                meetingFreeTimes[minMeetingFreeKaIndex] += meetings[i][1] - meetings[i][0];
            }
        }

        for (int i = 0; i < meetingCount.size(); i++) {
            if (meetingCount[i] > maxCount) {
                maxCount = meetingCount[i];
                maxCountKaINdex = i;
            }
        }

        return maxCountKaINdex;
    }
};
