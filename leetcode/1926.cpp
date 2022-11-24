class Solution
{
public:
    vector<vector<int>> dirs = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

    bool is_exit(const int &m, const int &n, const int &i, const int &j)
    {
        return ((i == 0 || i == m - 1) || (j == 0 || j == n - 1));
    }

    bool is_exit(const int &m, const int &n, vector<int> &cur)
    {
        return is_exit(m, n, cur[0], cur[1]);
    }

    bool is_valid(const int &m, const int &n, vector<int> &cur)
    {
        return cur[0] >= 0 && cur[0] < m && cur[1] >= 0 && cur[1] < n;
    }

    vector<vector<int>> get_4neighbors(const int &m, const int &n, vector<int> &cur)
    {
        vector<vector<int>> ret;
        for (const auto dir : dirs)
        {
            vector<int> neigh = {cur[0] + dir[0], cur[1] + dir[1]};
            if (is_valid(m, n, neigh))
            {
                ret.push_back(neigh);
            }
        }

        return ret;
    }

    void mark_visited(vector<vector<char>> &maze, const int &m, const int &n, vector<int> &cur)
    {
        assert(is_valid(m, n, cur));
        maze[cur[0]][cur[1]] = '+';
    }

    bool visited(vector<vector<char>> &maze, const int &m, const int &n, vector<int> &cur)
    {
        assert(is_valid(m, n, cur));
        return maze[cur[0]][cur[1]] == '+';
    }

    int nearestExit(vector<vector<char>> maze, vector<int> &entrance)
    {
        int m = maze.size(), n = maze[0].size();

        queue<vector<int>> q;
        q.push(entrance);
        mark_visited(maze, m, n, entrance);
        int steps = 0;
        while (q.size())
        {
            int q_n = q.size();
            while (q_n--)
            {
                auto cur = q.front();
                printf("cur (%d,%d)\n", cur[0], cur[1]);
                q.pop();
                if (cur != entrance && is_exit(m, n, cur))
                {
                    return steps;
                }
                for (auto neigh : get_4neighbors(m, n, cur))
                {
                    if (!visited(maze, m, n, neigh))
                    {
                        mark_visited(maze, m, n, neigh);
                        q.push(neigh);
                    }
                }
            }
            ++steps;
        }
        return -1;
    }
};