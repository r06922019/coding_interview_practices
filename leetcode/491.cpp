class Solution
{
public:
    void solve(vector<int> &nums, int i, vector<int> &buf, set<vector<int>> &ans)
    {
        if (i == nums.size())
        {
            if (buf.size() >= 2)
            {
                ans.insert(buf);
            }
            return;
        }
        solve(nums, i + 1, buf, ans);
        if (buf.size() == 0 || buf.back() <= nums[i])
        {
            buf.push_back(nums[i]);
            solve(nums, i + 1, buf, ans);
            buf.pop_back();
        }
    }
    vector<vector<int>> findSubsequences(vector<int> &nums)
    {
        set<vector<int>> ans;
        vector<int> buf;
        solve(nums, 0, buf, ans);
        return vector<vector<int>>(ans.begin(), ans.end());
    }
};