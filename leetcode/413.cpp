class Solution
{
public:
    int numberOfArithmeticSlices(vector<int> &nums)
    {
        if (nums.size() < 3)
            return 0;
        vector<int> diffs;
        for (int i = 1; i < nums.size(); ++i)
        {
            diffs.push_back(nums[i] - nums[i - 1]);
        }

        int ans = 0, starting_index = 0;
        for (int i = 1; i <= diffs.size(); ++i)
        {
            if (i == diffs.size() || diffs[i] != diffs[starting_index])
            {
                int w = i - starting_index;
                ans += (w * (w - 1)) >> 1;
                starting_index = i;
            }
        }
        return ans;
    }
};