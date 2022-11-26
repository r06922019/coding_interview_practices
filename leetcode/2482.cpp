class Solution
{
public:
    vector<vector<int>> onesMinusZeros(vector<vector<int>> &grid)
    {
        int m = grid.size(), n = grid[0].size();
        vector<int> rows(m, 0), cols(n, 0);
        for (int i = 0; i < m; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                rows[i] += grid[i][j];
                cols[j] += grid[i][j];
            }
        }

        auto ans = grid;
        for (int i = 0; i < m; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                ans[i][j] = 2 * (rows[i] + cols[j]) - m - n;
            }
        }
        return ans;
    }
};