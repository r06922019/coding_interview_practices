class Solution
{
public:
    long long numberOfWays(string s)
    {
        vector<int> totals(2, 0);
        for (auto c : s)
        {
            ++totals[c - '0'];
        }

        long long ans = 0;
        for (int i = 0; i <= 1; ++i)
        {
            char target = i + '0';
            int not_target_seen = 0;
            for (auto c : s)
            {
                if (c == target)
                {
                    long long tmp = 1;
                    tmp *= not_target_seen;
                    tmp *= totals[i ^ 1] - not_target_seen;
                    ans += tmp;
                }
                else
                {
                    ++not_target_seen;
                }
            }
        }
        return ans;
    }
};