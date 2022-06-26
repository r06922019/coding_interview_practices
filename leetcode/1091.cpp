class Solution
{
public:
    int bfs_shortest_length(unordered_map<int, vector<int> > &adj_lists, int start, int target)
    {
        queue<int> q;
        unordered_set<int> visited;

        int steps = 1;
        q.push(start);
        visited.insert(start);
        while (q.size())
        {
            int q_n = q.size();
            while (q_n--)
            {
                int front = q.front();
                q.pop();
                if (front == target)
                    return steps;
                for (auto neigh : adj_lists[front])
                {
                    if (visited.find(neigh) == visited.end())
                    {
                        q.push(neigh);
                        visited.insert(neigh);
                    }
                }
            }
            ++steps;
        }
        return -1;
    }

    bool is_valid(vector<vector<int> > &grid, int i, int j)
    {
        return i >= 0 && i < grid.size() && j >= 0 && j < grid[i].size();
    }

    int coord_2d_to_1d(vector<vector<int> > &grid, int i, int j)
    {
        return i * grid[0].size() + j;
    }

    int shortestPathBinaryMatrix(vector<vector<int> > &grid)
    {
        int m = grid.size(), n = grid[0].size();
        unordered_map<int, vector<int> > adj_lists;
        vector<vector<int> > dirs = {
            {0, 1}, {1, 0}, {1, 1}, {1, -1}};
        for (int i = 0; i < m; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                if (grid[i][j] == 0)
                {
                    int a = coord_2d_to_1d(grid, i, j);
                    for (auto dir : dirs)
                    {
                        int ni = i + dir[0], nj = j + dir[1];
                        if (is_valid(grid, ni, nj) && grid[ni][nj] == 0)
                        {
                            int b = coord_2d_to_1d(grid, ni, nj);
                            adj_lists[a].push_back(b);
                            adj_lists[b].push_back(a);
                        }
                    }
                }
            }
        }

        return bfs_shortest_length(adj_lists, 0, m * n - 1);
    }
};