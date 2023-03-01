class Solution
{
public:
    const int method = 1;
    void expand_palin(string &s, int l, int r, string &ans)
    {
        if (l < 0 || r >= s.size() || s[l] != s[r])
            return;
        while ((l - 1) >= 0 && (r + 1) < s.size() && s[l - 1] == s[r + 1])
        {
            --l;
            ++r;
        }
        if ((r - l + 1) > ans.size())
        {
            ans = s.substr(l, (r - l + 1));
        }
    }

    string longestPalindrome(string s)
    {
        int n = s.size();
        if (n == 1)
            return s;
        if (method == 0)
        {
            string ans = "";
            for (int i = 0; i < n; ++i)
            {
                expand_palin(s, i, i, ans);
                expand_palin(s, i, i + 1, ans);
            }
            return ans;
        }
        else
        {
            vector<vector<int>> lps(n, vector<int>(n, 0));
            string s_r(s.rbegin(), s.rend());
            int max_len = 0, max_end_index = -1;
            for (int i = 0; i < n; ++i)
            {
                for (int j = 0; j < n; ++j)
                {
                    if (s[i] == s_r[j])
                    {
                        if (i == 0 || j == 0)
                        {
                            lps[i][j] = 1;
                        }
                        else
                        {
                            lps[i][j] = 1 + lps[i - 1][j - 1];
                        }
                        if (lps[i][j] > max_len)
                        {
                            int s_l = i - lps[i][j] + 1;
                            int s_r = i;
                            int s_r_l = j - lps[i][j] + 1;
                            int s_r_r = j;

                            if (s_l == (n - 1 - s_r_r) && s_r == (n - 1 - s_r_l))
                            {
                                max_len = lps[i][j];
                                max_end_index = i;
                            }
                        }
                    }
                }
            }
            return s.substr(max_end_index - max_len + 1, max_len);
        }
        return "";
    }
};