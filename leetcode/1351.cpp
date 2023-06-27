class Solution
{
public:
    int countNegatives(vector<vector<int>> &grid)
    {
        int ans = 0;
        for (int i = 0, j = grid[0].size(); i < grid.size(); ++i)
        {
            while (j > 0 && grid[i][j - 1] < 0)
                --j;
            ans += grid[0].size() - j;
        }
        return ans;
    }
};