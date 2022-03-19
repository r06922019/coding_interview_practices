class Solution
{
public:
    int minimumWhiteTiles(string floor, int numCarpets, int carpetLen)
    {
        int n = floor.size();
        vector<vector<int> > dp(numCarpets + 1, vector<int>(n + 1, -1));
        dp[0][0] = 0;
        for (int j = 1; j <= n; ++j)
        {
            dp[0][j] = dp[0][j - 1] + floor[j - 1] - '0';
        }
        for (int i = 1; i <= numCarpets; ++i)
        {
            dp[i][0] = 0;
        }

        for (int i = 1; i <= numCarpets; ++i)
        {
            int min_val = 1001;
            for (int j = 1; j <= n; ++j)
            {
                // j is the len covered
                if (floor[j - 1] == '1')
                {
                    if (j <= carpetLen)
                    {
                        dp[i][j] = 0;
                    }
                    else
                    {
                        dp[i][j] = min(dp[i - 1][j - carpetLen], min_val + dp[0][j]);
                        if (min_val > dp[i][j] - dp[0][j])
                            min_val = dp[i][j] - dp[0][j];
                    }
                }
                else
                {
                    dp[i][j] = dp[i][j - 1];
                }
            }
        }
        return dp[numCarpets][n];
    }
};