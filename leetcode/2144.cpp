class Solution
{
public:
    int minimumCost(vector<int> &cost)
    {
        sort(cost.begin(), cost.end());
        reverse(cost.begin(), cost.end());
        int ans = 0, bought = 0;
        for (int i = 0; i < cost.size(); ++i)
        {
            if (bought == 2)
            {
                bought = 0;
            }
            else
            {
                ans += cost[i];
                ++bought;
            }
        }
        return ans;
    }
};