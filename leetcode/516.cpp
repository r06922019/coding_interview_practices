class Solution
{
public:
    int lcs(string s1, int m, string s2, int n)
    {
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
        for (int i = 1; i <= m; ++i)
        {
            for (int j = 1; j <= n; ++j)
            {
                if (s1[i - 1] == s2[j - 1])
                {
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                }
                else
                {
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                }
            }
        }
        return dp[m][n];
    }
    int longestPalindromeSubseq(string s)
    {
        string s_(s.rbegin(), s.rend());
        return lcs(s, s.size(), s_, s_.size());
    }
};