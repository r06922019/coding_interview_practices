class Solution
{
public:
    void solve(string s, vector<int> &costs)
    {
        int n = s.size(), prev_cost = 0, prev_index = -1;
        for (int i = 0; i < n; ++i)
        {
            if (s[i] == '0')
            {
                costs[i] = prev_cost;
            }
            else
            {
                costs[i] = min(i + 1, 2 + prev_cost);
                prev_cost = costs[i];
            }
        }
    }

    int minimumTime(string s)
    {
        int n = s.size();
        vector<int> cost1(n, 0), cost2(n, 0);
        solve(s, cost1);
        reverse(s.begin(), s.end());
        solve(s, cost2);
        reverse(cost2.begin(), cost2.end());
        int cost = min(cost1[n - 1], cost2[0]);
        for (int i = 1; i < n; ++i)
        {
            cost = min(cost, cost1[i - 1] + cost2[i]);
        }
        return cost;
    }
};