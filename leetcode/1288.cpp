class Solution
{
public:
    int removeCoveredIntervals(vector<vector<int> > &intervals)
    {
        auto cmp = [](const vector<int> &a, vector<int> &b)
        {
            return (a[0] < b[0]) || (a[0] == b[0] && a[1] > b[1]);
        };
        sort(intervals.begin(), intervals.end(), cmp);

        int s = 0;
        vector<int> *cur = nullptr;
        for (auto &interval : intervals)
        {
            if (cur == nullptr || interval[1] > (*cur)[1])
            {
                ++s;
                cur = &interval;
            }
        }
        return s;
    }
};