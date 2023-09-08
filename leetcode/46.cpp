class Solution
{
public:
    vector<vector<int>> permute(vector<int> &nums)
    {
        vector<vector<int>> ans;
        vector<int> buf;
        unordered_set<int> used;
        helper(nums, used, buf, ans);
        return ans;
    }

    void helper(vector<int> &nums, unordered_set<int> &used,
                vector<int> &buf, vector<vector<int>> &ans)
    {

        if (used.size() == nums.size())
        {
            ans.push_back(buf);
        }

        for (int i = 0; i < nums.size(); ++i)
        {
            if (used.find(i) == used.end())
            {
                used.insert(i);
                buf.push_back(nums[i]);
                helper(nums, used, buf, ans);
                used.erase(i);
                buf.pop_back();
            }
        }
    }
};