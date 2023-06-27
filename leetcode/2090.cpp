class Solution
{
public:
    vector<int> getAverages(vector<int> &nums, int k)
    {
        const int len = 2 * k + 1;
        if (nums.size() < len)
        {
            return vector<int>(nums.size(), -1);
        }
        vector<int> ans(k, -1);
        long long cur = 0;
        for (int i = 0; i < nums.size(); ++i)
        {
            if (i >= len)
            {
                cur -= nums[i - len];
            }
            cur += nums[i];
            if (i >= len - 1)
                ans.push_back(cur / len);
        }
        for (int i = 0; i < k; ++i)
            ans.push_back(-1);
        return ans;
    }
};