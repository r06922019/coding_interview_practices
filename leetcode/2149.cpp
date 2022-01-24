class Solution
{
public:
    vector<int> rearrangeArray(vector<int> &nums)
    {
        vector<int> pos, neg;
        for (auto num : nums)
        {
            if (num > 0)
                pos.push_back(num);
            else
                neg.push_back(num);
        }
        int n = nums.size() / 2;
        vector<int> ans;
        for (int i = 0; i < n; ++i)
        {
            ans.push_back(pos[i]);
            ans.push_back(neg[i]);
        }
        return ans;
    }
};