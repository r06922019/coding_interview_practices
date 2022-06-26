class Solution
{
public:
    vector<int> runningSum(vector<int> &nums)
    {
        vector<int> ans;
        int cur_sum = 0;
        for (auto num : nums)
        {
            cur_sum += num;
            ans.push_back(cur_sum);
        }
        return ans;
    }
};