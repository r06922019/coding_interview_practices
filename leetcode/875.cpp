class Solution
{
public:
    bool try_eating(const vector<int> &piles, int k, int h)
    {
        int x = 0;
        for (auto &p : piles)
        {
            x += p / k;
            if (p % k)
                ++x;
        }
        return x <= h;
    }

    int minEatingSpeed(vector<int> &piles, int h)
    {
        int l = 1;
        int r = *max_element(piles.begin(), piles.end());

        while (l < r)
        {
            int mid = l + (r - l) / 2;

            if (try_eating(piles, mid, h))
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