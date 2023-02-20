class Solution
{
public:
    void helper(vector<vector<int>> &grid, const int m, const int n)
    {
        for (int i = 0; i < m; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                if (i > 0)
                    grid[i][j] = min(grid[i][j], grid[i - 1][j] + 1);
                if (j > 0)
                    grid[i][j] = min(grid[i][j], grid[i][j - 1] + 1);
            }
        }
    }

    int maxDistance(vector<vector<int>> &grid)
    {
        const int table[2] = {(int)1e4, 0};
        bool has[2] = {false, false};
        const int m = grid.size(), n = grid[0].size();
        for (int i = 0; i < m; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                has[grid[i][j]] = true;
                grid[i][j] = table[grid[i][j]];
            }
        }
        if (!(has[0] && has[1]))
            return -1;

        helper(grid, m, n);
        for (int i = 0; i < m; ++i)
        {
            reverse(grid[i].begin(), grid[i].end());
        }
        reverse(grid.begin(), grid.end());
        helper(grid, m, n);

        int ans = 0;
        for (int i = 0; i < m; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                ans = max(ans, grid[i][j]);
            }
        }
        return ans;
    }
};