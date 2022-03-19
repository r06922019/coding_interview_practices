class Solution
{
public:
#define V vector
#define BF
    bool isSubsequence(string s, string t)
    {
#ifdef BF
        reverse(s.begin(), s.end());
        for (auto c : t)
            if (s.size() && c == s.back())
                s.pop_back();
        return s.empty();
#endif
#ifdef DP
        int n_s = s.size(), n_t = t.size();
        V<V<int> > dp(n_t + 1, V<int>(n_s + 1, 0));

        for (int i = 0; i < n_t; ++i)
        {
            for (int j = 0; j < n_s; ++j)
            {
                if (t[i] == s[j])
                    dp[i + 1][j + 1] = dp[i][j] + 1;
                else
                    dp[i + 1][j + 1] = max(dp[i + 1][j], dp[i][j + 1]);
            }
        }
        return dp[n_t][n_s] == n_s;
#endif
    }
};