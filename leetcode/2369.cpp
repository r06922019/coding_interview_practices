class Solution
{
public:
    bool validPartition(vector<int> &nums)
    {
        const int n = nums.size();
        vector<bool> dp(n + 1, false);
        dp[0] = true;
        for (int i = 0; i < n; ++i)
        {
            if (i - 1 >= 0 && nums[i] == nums[i - 1])
            {
                dp[i + 1] = dp[i + 1] || dp[i + 1 - 2];
            }
            if (i - 2 >= 0 && nums[i] == nums[i - 1] && nums[i - 1] == nums[i - 2])
            {
                dp[i + 1] = dp[i + 1] || dp[i + 1 - 3];
            }
            if (i - 2 >= 0 && nums[i] == nums[i - 1] + 1 && nums[i - 1] == nums[i - 2] + 1)
            {
                dp[i + 1] = dp[i + 1] || dp[i + 1 - 3];
            }
        }
        return dp[n];
    }
};