class Solution
{
public:
    int triangularSum(vector<int> &nums)
    {
        while (nums.size() > 1)
        {
            vector<int> new_nums;
            for (int i = 1; i < nums.size(); ++i)
            {
                new_nums.push_back((nums[i] + nums[i - 1]) % 10);
            }
            nums = new_nums;
        }
        return nums[0];
    }
};