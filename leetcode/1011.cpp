class Solution
{
public:
    int check_days(vector<int> &weights, int ship)
    {
        int days = 1, cur_ship = 0;
        for (auto &w : weights)
        {
            if (cur_ship + w > ship)
            {
                ++days;
                cur_ship = 0;
            }
            cur_ship += w;
        }
        return days;
    }

    int shipWithinDays(vector<int> &weights, int days)
    {
        int l = *max_element(weights.begin(), weights.end());
        int r = accumulate(weights.begin(), weights.end(), 0);
        while (l < r)
        {
            int mid = l + (r - l) / 2;
            if (check_days(weights, mid) <= days)
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