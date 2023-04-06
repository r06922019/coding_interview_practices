class Solution
{
public:
    int dfs(vector<vector<int>> &grid,
            const int i, const int j,
            const int m, const int n)
    {
        if (i <= -1 || i >= m || j <= -1 || j >= n)
            return 1;
        if (grid[i][j] == 1)
            return 0;
        grid[i][j] = 1;
        return dfs(grid, i - 1, j, m, n) +
               dfs(grid, i, j - 1, m, n) +
               dfs(grid, i + 1, j, m, n) +
               dfs(grid, i, j + 1, m, n);
    }

    int closedIsland(vector<vector<int>> &grid)
    {
        int ans = 0;
        const int m = grid.size(), n = grid[0].size();
        for (int i = 0; i < m; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                if (grid[i][j] == 0 && dfs(grid, i, j, m, n) == 0)
                {
                    ++ans;
                }
            }
        }
        return ans;
    }
};