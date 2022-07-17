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

    int findPaths(int m, int n, int maxMove, int startRow, int startColumn)
    {
        if (maxMove == 0)
            return 0;
        int ans = 0;
        const vector<vector<int> > dirs = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        vector<vector<int> > results(m, vector<int>(n, 0));
        for (int i = 0; i < m; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                results[i][j] += (i == 0) + (j == 0) + (i == m - 1) + (j == n - 1);
            }
        }
        ans = add(ans, results[startRow][startColumn]);
        for (int move = 2; move <= maxMove; ++move)
        {
            vector<vector<int> > new_results(m, vector<int>(n, 0));
            for (int i = 0; i < m; ++i)
            {
                for (int j = 0; j < n; ++j)
                {
                    for (auto dir : dirs)
                    {
                        int ni = i + dir[0];
                        int nj = j + dir[1];
                        if (ni >= 0 && ni < m && nj >= 0 && nj < n)
                            new_results[ni][nj] = add(new_results[ni][nj], results[i][j]);
                    }
                }
            }
            results = new_results;
            ans = add(ans, results[startRow][startColumn]);
        }
        return ans;
    }
};