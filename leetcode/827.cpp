class Solution {
public:
    bool is_valid(vector<vector<int>>& grid, const int m, const int n,
                  const int i, const int j) {
        return i >= 0 && i < m && j >= 0 && j < n;
    }

    int dfs(vector<vector<int>>& grid, const int m, const int n, const int i,
            const int j, const int group_id) {
        if (!is_valid(grid, m, n, i, j) || grid[i][j] != 1)
            return 0;
        int ret = 1;
        grid[i][j] = group_id;
        ret += dfs(grid, m, n, i - 1, j, group_id);
        ret += dfs(grid, m, n, i + 1, j, group_id);
        ret += dfs(grid, m, n, i, j - 1, group_id);
        ret += dfs(grid, m, n, i, j + 1, group_id);
        return ret;
    }

    int largestIsland(vector<vector<int>>& grid) {
        unordered_map<int, int> areas = {{0, 0}};
        const int m = grid.size(), n = grid[0].size();
        int cur_group = -1; // negative group id
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                areas[cur_group] = dfs(grid, m, n, i, j, cur_group);
                cur_group = cur_group - 1;
            }
        }

        int ans = 0;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == 0) {
                    unordered_set<int> groups;
                    if (is_valid(grid, m, n, i - 1, j))
                        groups.insert(grid[i - 1][j]);
                    if (is_valid(grid, m, n, i + 1, j))
                        groups.insert(grid[i + 1][j]);
                    if (is_valid(grid, m, n, i, j - 1))
                        groups.insert(grid[i][j - 1]);
                    if (is_valid(grid, m, n, i, j + 1))
                        groups.insert(grid[i][j + 1]);
                    int cur_ans = 1;
                    for (auto g : groups)
                        cur_ans += areas[g];
                    ans = max(ans, cur_ans);
                } else {
                    ans = max(ans, areas[grid[i][j]]);
                }
            }
        }

        return ans;
    }
};
