class Solution
{
public:
    vector<int> findAnagrams(string s, string p)
    {
        vector<int> ans;
        vector<int> c_s(26, 0), c_p(26, 0);
        for (auto c : p)
            ++c_p[c - 'a'];
        for (int i = 0; i < s.size(); ++i)
        {
            if (i >= p.size() - 1)
            {
                if (i >= p.size())
                {
                    --c_s[s[i - p.size()] - 'a'];
                }
                ++c_s[s[i] - 'a'];
                if (c_s == c_p)
                    ans.push_back(i - p.size() + 1);
            }
            else
            {
                ++c_s[s[i] - 'a'];
            }
        }
        return ans;
    }
};