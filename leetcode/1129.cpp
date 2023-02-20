class Item
{
public:
    int index, next_color;
    Item(int _i, int _n) : index(_i), next_color(_n)
    {
    }
};

class Solution
{
public:
    const int N_COLOR = 2;
    vector<int> shortestAlternatingPaths(int n, vector<vector<int>> &redEdges, vector<vector<int>> &blueEdges)
    {
        vector<unordered_map<int, vector<int>>> adj_lists(N_COLOR, unordered_map<int, vector<int>>());
        for (auto e : redEdges)
        {
            const auto a = e[0], b = e[1];
            adj_lists[0][a].push_back(b);
        }
        for (auto e : blueEdges)
        {
            const auto a = e[0], b = e[1];
            adj_lists[1][a].push_back(b);
        }

        vector<unordered_map<int, int>> visited(N_COLOR, unordered_map<int, int>());
        queue<Item> q; // q: index, color
        int steps = 1;
        for (int c = 0; c < N_COLOR; ++c)
        {
            visited[c][0] = 0, q.push(Item(0, c));
        }
        while (q.size())
        {
            int q_n = q.size();
            while (q_n--)
            {
                auto cur = q.front();
                q.pop();
                const int cur_index = cur.index, next_color = cur.next_color;
                for (auto next_index : adj_lists[next_color][cur_index])
                {
                    if (visited[next_color].find(next_index) == visited[next_color].end())
                    {
                        visited[next_color][next_index] = steps;
                        q.push(Item(next_index, next_color ^ 1));
                    }
                }
            }
            ++steps;
        }

        vector<int> ans(n, -1);
        ans[0] = 0;
        for (int i = 1; i < n; ++i)
        {
            int tmp = -1;
            for (int j = 0; j < N_COLOR; ++j)
            {
                if (visited[j].find(i) != visited[j].end() && (tmp == -1 || visited[j][i] < tmp))
                {
                    tmp = visited[j][i];
                }
            }
            ans[i] = tmp;
        }
        return ans;
    }
};