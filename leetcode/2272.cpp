class Solution
{
public:
    int try_c1c2(string s, const char &c1, const char &c2)
    {
        int ans = 0, cur = 0;
        bool have_c2 = false;
        for (int i = 0; i < s.size(); ++i)
        {
            const auto c = s[i];
            if (c == c1)
            {
                cur += 1;
            }
            else if (c == c2)
            {
                cur -= 1;
                have_c2 = true;
            }
            if (cur < 0)
            {
                have_c2 = false;
                cur = 0;
            }
            if (have_c2)
                ans = max(ans, cur);
            else
                ans = max(ans, cur - 1);
        }
        return ans;
    }

    int largestVariance(string s)
    {
        vector<int> counter(26, 0);
        for (auto c : s)
            ++counter[c - 'a'];
        int ans = 0;
        for (char c1 = 'a'; c1 <= 'z'; ++c1)
        {
            if (counter[c1 - 'a'] == 0)
                continue;
            for (char c2 = 'a'; c2 <= 'z'; ++c2)
            {
                if (counter[c2 - 'a'] == 0)
                    continue;
                if (c1 == c2)
                    continue;
                ans = max(ans, try_c1c2(s, c1, c2));
            }
        }
        return ans;
    }
};