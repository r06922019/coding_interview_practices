class Solution
{
public:
    vector<int> findErrorNums(vector<int> nums)
    {
        vector<int> ans = {0, 0};
        for (int i = 0; i < nums.size(); ++i)
        {
            const auto x = nums[i];
            const auto index = abs(x) - 1;
            if (nums[index] < 0)
            {
                ans[0] = abs(x);
            }
            else
            {
                nums[index] = -nums[index];
            }
        }
        for (int i = 0; i < nums.size(); ++i)
        {
            if (nums[i] > 0)
            {
                ans[1] = i + 1;
                break;
            }
        }
        return ans;
    }
};