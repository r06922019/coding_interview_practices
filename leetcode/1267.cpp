class Solution {
public:
    int countServers(vector<vector<int>>& grid) {
        vector<int> grid_i(grid.size(), 0), grid_j(grid[0].size(), 0);
        for (int i = 0; i < grid.size(); ++i) {
            for (int j = 0; j < grid[i].size(); ++j) {
                grid_i[i] += grid[i][j];
                grid_j[j] += grid[i][j];
            }
        }

        int ans = 0;
        for (int i = 0; i < grid.size(); ++i) {
            for (int j = 0; j < grid[i].size(); ++j) {
                if (grid[i][j] == 1) {
                    if (grid_i[i] >= 2 || grid_j[j] >= 2)
                        ++ans;
                }
            }
        }
        return ans;
    }
};
