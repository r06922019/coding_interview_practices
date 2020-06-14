class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> dp(m, vector<int>(n, INT_MAX));
        for(int i = 0; i < m; ++i) {
            for(int j = 0; j < n; ++j) {
                int &cur = grid[i][j];
                if(i == 0 && j == 0)
                    dp[i][j] = cur;
                else if(i == 0)
                    dp[i][j] = dp[i][j-1] + cur;
                else if(j == 0)
                    dp[i][j] = dp[i-1][j] + cur;
                else
                    dp[i][j] = min(dp[i-1][j], dp[i][j-1]) + cur;
            }
        }
        return dp[m-1][n-1];
    }
};