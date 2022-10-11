class Solution
{
public:
    vector<int> findOriginalArray(vector<int> &changed)
    {
        map<int, int> mp;
        for (auto x : changed)
        {
            ++mp[x];
        }
        vector<int> ans;
        while (mp.size())
        {
            auto cur = mp.begin()->first;
            ans.push_back(cur);
            if (mp[cur] == 1)
            {
                mp.erase(cur);
            }
            else
            {
                --mp[cur];
            }
            auto cur2 = cur << 1;
            if (mp.find(cur2) == mp.end())
            {
                return {};
            }
            else
            {
                if (mp[cur2] == 1)
                {
                    mp.erase(cur2);
                }
                else
                {
                    --mp[cur2];
                }
            }
        }
        return ans;
    }
};