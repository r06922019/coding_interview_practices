class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        sort(points.begin(), points.end(), [](const vector<int> &a, const vector<int> &b) {
            return a[1] < b[1];
        });

        int cnt = 0;
        int *cur_end = nullptr;
        for(auto &point : points) {
            if(cur_end == nullptr || *cur_end < point[0]) {
                ++cnt;
                cur_end = &point[1];
            }
        }
        return cnt;
    }
};