class Solution
{
public:
    int minimizeArrayValue(vector<int> &nums)
    {
        int ans = nums[0];
        long long cur_sum = nums[0];
        for (int i = 1, n = 2; i < nums.size(); ++i, ++n)
        {
            cur_sum += nums[i];
            int cur_ans = cur_sum / n;
            if (cur_sum % n)
                ++cur_ans;
            ans = max(ans, cur_ans);
        }
        return ans;
    }
};