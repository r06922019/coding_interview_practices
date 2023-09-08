class Solution
{
public:
    bool can_do(vector<int> &dist, const int speed, double hour)
    {
        double spent = 0;
        for (int i = 0; i < dist.size(); ++i)
        {
            double d = dist[i];
            if (i + 1 == dist.size())
            {
                spent += (d / speed);
            }
            else
            {
                spent += ceil(d / speed);
            }
        }
        return spent <= hour;
    }
    int minSpeedOnTime(vector<int> &dist, double hour)
    {
        if (hour + 1 <= dist.size())
            return -1;
        int l = 1, r = *max_element(dist.begin(), dist.end()) * 100;
        while (l < r)
        {
            const int mid = l + (r - l) / 2;
            if (can_do(dist, mid, hour))
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