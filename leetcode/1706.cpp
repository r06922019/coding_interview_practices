class Solution
{
public:
    unordered_map<char, unordered_map<int, char>> cur_to_next_dir = {
        {'D', {{1, 'R'}, {-1, 'L'}}},
        {'L', {{-1, 'D'}}},
        {'R', {{1, 'D'}}},
    };
    unordered_map<char, vector<int>> dir_to_delta = {
        {'D', {1, 0}},
        {'L', {0, -1}},
        {'R', {0, 1}},
    };

    int drop_the_ball(const vector<vector<int>> &grid, char cur, int i, int j, const int &m, const int &n)
    {
        while (i < m && j >= 0 && j < n)
        {
            const int &cur_board = grid[i][j];
            if (cur_to_next_dir[cur].find(cur_board) == cur_to_next_dir[cur].end())
                return -1;
            cur = cur_to_next_dir[cur][cur_board];
            const auto &delta = dir_to_delta[cur];
            i += delta[0];
            j += delta[1];
        }
        return (i < m) ? -1 : j;
    }
    vector<int> findBall(vector<vector<int>> &grid)
    {
        const int m = grid.size(), n = grid[0].size();
        vector<int> ans(n, -1);
        for (int j = 0; j < n; ++j)
        {
            ans[j] = drop_the_ball(grid, 'D', 0, j, m, n);
        }
        return ans;
    }
};