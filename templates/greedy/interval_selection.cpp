// https://en.wikipedia.org/wiki/Interval_scheduling#Interval_Scheduling_Maximization
class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), [](const vector<int> &a, const vector<int> &b) {
            return a[1] < b[1];
        });
        int cnt = 0, cur_end = INT_MIN;
        for(auto &interval : intervals) {
            if(cur_end <= interval[0]) {
                ++cnt;
                cur_end = interval[1];
            }
        }
        return intervals.size() - cnt;
    }
};