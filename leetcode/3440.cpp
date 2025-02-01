class Solution {
public:
    int maxFreeTime(int eventTime, vector<int>& startTime, vector<int>& endTime) {
        const int n = startTime.size();
        vector<int> empty_times;
        for(int i = 0, prev_end = 0; i < n; ++i) {
            empty_times.push_back(startTime[i] - prev_end);
            prev_end = endTime[i];
        }
        empty_times.push_back(eventTime - endTime.back());
        // empty_times should be size n+1
        vector<int> left_max(n, -1), right_max(n, -1);
        for(int i = 1, prev_max = empty_times[0]; i < n; ++i) {
            left_max[i] = prev_max;
            prev_max = max(prev_max, empty_times[i]);
        }
        for(int i = n-2, prev_max = empty_times[n]; i >=0; --i) {
            right_max[i] = prev_max;
            prev_max = max(prev_max, empty_times[i+1]);
        }
        int ans = 0;
        for(int i = 0; i < n; ++i) {
            ans = max(ans, empty_times[i] + empty_times[i+1]);
            const int cur_time = endTime[i] - startTime[i];
            if(cur_time <= right_max[i] || cur_time <= left_max[i]) {
                ans = max(ans, empty_times[i] + cur_time + empty_times[i+1]);
            }
        }
        return ans;
    }
};
