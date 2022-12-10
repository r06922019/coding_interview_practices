class Solution
{
public:
    bool can_do(vector<int> stones, int x)
    {
        int n = stones.size();
        for (int i = 0, prev = stones[0]; i < n; ++i)
        {
            if (stones[i] - prev > x)
            {
                prev = stones[i - 1];
                stones[i - 1] *= -1;
            }
            if (stones[i] - prev > x)
                return false;
        }
        for (int j = n - 1, prev = stones[n - 1]; j >= 0; --j)
        {
            if (stones[j] >= 0)
            {
                if ((prev - stones[j]) > x)
                    return false;
                prev = stones[j];
            }
        }
        return true;
    }

    int maxJump(vector<int> &stones)
    {
        int l = 0, r = stones.back() - stones[0];
        while (l < r)
        {
            int mid = l + (r - l) / 2;
            if (can_do(stones, mid))
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