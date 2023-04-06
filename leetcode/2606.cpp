class Solution
{
public:
    int maximumCostSubstring(string s, string chars, vector<int> &vals)
    {
        vector<int> costs(26, 0);
        for (int i = 0; i < 26; ++i)
        {
            costs[i] = i + 1;
        }
        for (int i = 0; i < chars.size(); ++i)
        {
            costs[chars[i] - 'a'] = vals[i];
        }
        int ans = 0, cur_ans = 0;
        for (auto c : s)
        {
            cur_ans = max(cur_ans + costs[c - 'a'], 0);
            ans = max(ans, cur_ans);
        }
        return ans;
    }
};