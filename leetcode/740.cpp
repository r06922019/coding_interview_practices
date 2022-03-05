class Solution
{
public:
    int deleteAndEarn(vector<int> &nums)
    {
        vector<int> counter(1e4 + 1, 0);
        for (auto num : nums)
        {
            ++counter[num];
        }
        int ans = 0;
        vector<int> dp(1e4 + 1, 0);
        dp[1] = counter[1];
        for (int i = 2; i < dp.size(); ++i)
        {
            dp[i] = max(dp[i - 1], dp[i - 2] + counter[i] * i);
        }
        return dp.back();
    }
};