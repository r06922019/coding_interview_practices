class Solution
{
public:
    long long findScore(vector<int> &nums)
    {
        set<pair<int, int>> s;
        for (int i = 0; i < nums.size(); ++i)
            s.insert({nums[i], i});
        long long ans = 0;
        while (s.size())
        {
            auto cur = *s.begin();
            s.erase(cur);
            ans += cur.first;
            for (auto index : {cur.second - 1, cur.second + 1})
                if (index >= 0 && index < nums.size())
                    s.erase({nums[index], index});
        }
        return ans;
    }
};