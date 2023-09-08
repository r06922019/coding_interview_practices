class Solution
{
public:
    int count_ones(int num)
    {
        if (num <= 0)
            return 0;
        int cnt = 0;
        while (num)
        {
            num &= (num - 1);
            ++cnt;
        }
        return cnt;
    }
    bool can_do(const int n, const int mask,
                vector<vector<int>> &requests)
    {
        vector<int> net(n, 0);
        for (int i = 0; i < requests.size(); ++i)
        {
            if (mask & (1 << i))
            {
                --net[requests[i][0]];
                ++net[requests[i][1]];
            }
        }

        for (auto x : net)
            if (x)
                return false;
        return true;
    }
    int maximumRequests(int n, vector<vector<int>> &requests)
    {
        const int r = requests.size();
        int ans = 0;
        for (int m = 0; m < (1 << r); ++m)
        {
            if (can_do(n, m, requests))
            {
                ans = max(ans, count_ones(m));
            }
        }
        return ans;
    }
};