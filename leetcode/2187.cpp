class Solution
{
public:
    bool check(vector<int> &time, const long long total_time, const int totalTrips)
    {
        long long ans = 0;
        for (auto t : time)
            ans += total_time / t;
        return ans >= totalTrips;
    }

    long long minimumTime(vector<int> &time, int totalTrips)
    {
        long long l = 0, r = *min_element(time.begin(), time.end()) * (long long)totalTrips;
        while (l < r)
        {
            const long long mid = l + (r - l) / 2;
            if (check(time, mid, totalTrips))
            {
                r = mid;
            }
            else
            {
                l = mid + 1;
            }
        }
        return l;
    }
};