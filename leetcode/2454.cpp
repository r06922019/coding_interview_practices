class Solution
{
public:
    vector<int> secondGreaterElement(vector<int> nums)
    {
        const int n = nums.size();
        vector<int> ans(n, -1), s0, s1, tmp;
        for (int i = 0; i < n; ++i)
        {
            tmp.clear();
            while (s1.size() && nums[s1.back()] < nums[i])
            {
                ans[s1.back()] = nums[i];
                s1.pop_back();
            }
            while (s0.size() && nums[s0.back()] < nums[i])
            {
                tmp.push_back(s0.back());
                s0.pop_back();
            }
            while (tmp.size())
            {
                s1.push_back(tmp.back());
                tmp.pop_back();
            }
            s0.push_back(i);
        }
        return ans;
    }
};