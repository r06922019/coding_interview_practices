class Solution
{
public:
    const int MOD = 1e9 + 7;
    int mod(const int &x)
    {
        return x % MOD;
    }

    int add(const int &a, const int &b)
    {
        return mod(mod(a) + mod(b));
    }

    int sub(const int &a, const int &b)
    {
        return mod(mod(a) + MOD - mod(b));
    }

    int kInversePairs(int n, int k)
    {
        vector<vector<int> > cache(n + 1, vector<int>(k + 1, 0));
        // cache[0] = vector<int>(k+1, 0);
        for (int i = 1; i <= n; ++i)
        {
            cache[i][0] = 1;
            for (int j = 1; j <= k && j <= i * (i - 1) / 2; ++j)
            {
                // original sum
                // for(int m = 0; m <= min(j,i-1); ++m)
                //     cache[i][j] = add(cache[i][j], cache[i-1][j-m]);

                // from (j-m) to x
                // for(int x = j-min(j,i-1); x <= j; ++x)
                //     cache[i][j] = add(cache[i][j], cache[i-1][x]);

                // cache the sums
                cache[i][j] = add(cache[i][j - 1], cache[i - 1][j]);
                int to_sub = j - (i - 1) - 1;
                if (to_sub >= 0)
                    cache[i][j] = sub(cache[i][j], cache[i - 1][to_sub]);
            }
        }
        return cache[n][k];
    }
};