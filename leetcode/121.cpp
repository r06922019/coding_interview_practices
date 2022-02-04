class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        int ans = 0, prev_max = 0;
        reverse(prices.begin(), prices.end());
        for (auto p : prices)
        {
            ans = max(ans, prev_max - p);
            prev_max = max(prev_max, p);
        }
        return ans;
    }
};