class State
{
public:
    int steps, elim, i, j;
    State(int _i, int _j, int _steps, int _elim)
    {
        i = _i, j = _j, steps = _steps, elim = _elim;
    }
};

class Solution
{
public:
    const vector<vector<int>> dirs = {
        {1, 0}, {-1, 0}, {0, 1}, {0, -1}};

    bool is_valid(const State &cur, const vector<vector<int>> &grid)
    {
        return cur.i >= 0 && cur.j >= 0 && cur.i < grid.size() && cur.j < grid[0].size();
    }

    vector<State> get_neighbors(const State &cur, const vector<vector<int>> &grid)
    {
        vector<State> ret;
        for (const auto &dir : dirs)
        {
            State next(cur.i + dir[0], cur.j + dir[1], cur.steps + 1, cur.elim);
            if (is_valid(next, grid))
            {
                if (grid[next.i][next.j] == 0 || next.elim > 0)
                {
                    if (grid[next.i][next.j] == 1)
                    {
                        --next.elim;
                    }
                    ret.push_back(next);
                }
            }
        }

        return ret;
    }

    int shortestPath(vector<vector<int>> &grid, int k)
    {
        int m = grid.size(), n = grid[0].size();

        queue<State> q;
        vector<vector<int>> visited(m, vector<int>(n, -1)); // stores elim

        q.push(State(0, 0, 0, k));
        visited[0][0] = k;
        while (q.size())
        {
            int q_n = q.size();
            while (q_n--)
            {
                auto cur = q.front();
                q.pop();
                if (cur.i == m - 1 && cur.j == n - 1)
                    return cur.steps;
                for (auto x : get_neighbors(cur, grid))
                {
                    auto &v = visited[x.i][x.j];
                    if (v == -1 || v < x.elim)
                    {
                        q.push(x);
                        v = x.elim;
                    }
                }
            }
        }
        return -1;
    }
};