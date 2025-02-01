class Solution {
public:
    int maxFreeTime(int eventTime, int k, vector<int>& startTime,
                    vector<int>& endTime) {
        const int n = startTime.size();
        vector<int> empty_times;
        for (int i = 0, prev_end = 0; i < n; ++i) {
            const int empty_time = startTime[i] - prev_end;
            empty_times.push_back(empty_time);
            prev_end = endTime[i];
        }
        if (eventTime - endTime.back() > 0)
            empty_times.push_back(eventTime - endTime.back());
        if (empty_times.size() < k + 1)
            return accumulate(empty_times.begin(), empty_times.end(), 0);
        int cur_ans =
            accumulate(empty_times.begin(), empty_times.begin() + k + 1, 0);
        int ans = cur_ans;
        for (int i = k + 1; i < empty_times.size(); ++i) {
            cur_ans = cur_ans - empty_times[i - (k + 1)] + empty_times[i];
            ans = max(ans, cur_ans);
        }
        return ans;
    }
};
