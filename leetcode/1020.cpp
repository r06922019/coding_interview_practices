class Solution
{
public:
    void dfs(vector<vector<int>> &grid,
             const int i, const int j,
             const int m, const int n)
    {
        if (i <= -1 || i >= m || j <= -1 || j >= n || grid[i][j] == 0)
            return;
        grid[i][j] = 0;
        dfs(grid, i - 1, j, m, n);
        dfs(grid, i, j - 1, m, n);
        dfs(grid, i + 1, j, m, n);
        dfs(grid, i, j + 1, m, n);
    }
    int numEnclaves(vector<vector<int>> &grid)
    {
        const int m = grid.size(), n = grid[0].size();
        for (int i = 0; i < m; ++i)
            for (int j = 0; j < n; ++j)
                if (i == 0 || i == m - 1 || j == 0 || j == n - 1)
                    dfs(grid, i, j, m, n);
        int ans = 0;
        for (int i = 0; i < m; ++i)
            for (int j = 0; j < n; ++j)
                ans += grid[i][j];
        return ans;
    }
};