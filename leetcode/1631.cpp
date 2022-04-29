class Node
{
public:
    int index = 0, cost = 0;
    Node(int _index, int _cost)
    {
        index = _index;
        cost = _cost;
    }
};

class Solution
{
public:
    int minimumEffortPath(vector<vector<int> > &heights)
    {
        int m = heights.size(), n = heights[0].size();
        vector<vector<Node> > adj_list(m * n, vector<Node>());
        const vector<vector<int> > dirs = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        for (int i = 0; i < m; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                int cur_index = i * n + j;
                for (const auto &dir : dirs)
                {
                    int ni = i + dir[0], nj = j + dir[1];
                    if (ni >= 0 && ni < m && nj >= 0 && nj < n)
                    {
                        int new_index = ni * n + nj;
                        int cost = abs(heights[ni][nj] - heights[i][j]);
                        adj_list[cur_index].push_back(Node(new_index, cost));
                    }
                }
            }
        }

        vector<bool> visited(m * n, false);
        const int target = m * n - 1;
        int ans = -1;
        auto cmp = [](const Node &a, const Node &b)
        { return a.cost > b.cost; };
        priority_queue<Node, vector<Node>, decltype(cmp)> pq(cmp);

        pq.push(Node(0, 0));
        while (pq.size())
        {
            auto top = pq.top();
            pq.pop();
            if (visited[top.index])
                continue;
            if (top.index == target)
            {
                ans = top.cost;
                break;
            }
            visited[top.index] = true;
            for (auto neigh : adj_list[top.index])
            {
                if (!visited[neigh.index])
                {
                    neigh.cost = max(neigh.cost, top.cost);
                    pq.push(neigh);
                }
            }
        }
        return ans;
    }
};