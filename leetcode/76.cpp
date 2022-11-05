class Solution
{
public:
    string minWindow(string s, string t)
    {
        unordered_map<char, int> t_counter, s_counter;
        for (auto &c : t)
        {
            ++t_counter[c];
        }
        string ans = "";
        int matched = 0, l = 0;
        for (int r = 0; r < s.size(); ++r)
        {
            ++s_counter[s[r]];
            if (t_counter.find(s[r]) != t_counter.end() &&
                s_counter[s[r]] == t_counter[s[r]])
            {
                ++matched;
            }
            if (matched == t_counter.size())
            {
                // pop to get the minimum
                while (t_counter.find(s[l]) == t_counter.end() ||
                       s_counter[s[l]] > t_counter[s[l]])
                {
                    --s_counter[s[l]];
                    ++l;
                }
                // record ans
                if (ans == "" || ans.size() > r - l + 1)
                {
                    ans = s.substr(l, r - l + 1);
                }
            }
            // pop an extra to create space
            while (matched == t_counter.size())
            {
                if (t_counter.find(s[l]) != t_counter.end() && s_counter[s[l]] == t_counter[s[l]])
                {
                    --matched;
                }
                --s_counter[s[l]];
                ++l;
            }
        }
        return ans;
    }
};