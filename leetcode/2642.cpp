class Graph
{
public:
    int n;
    unordered_map<int, unordered_map<int, int>> adj_lists;

    Graph(int n_, vector<vector<int>> &edges)
    {
        n = n_;
        for (auto e : edges)
        {
            const auto from = e[0], to = e[1], cost = e[2];
            adj_lists[from][to] = cost;
        }
    }

    void addEdge(vector<int> e)
    {
        const auto from = e[0], to = e[1], cost = e[2];
        // no repeated edges
        adj_lists[from][to] = cost;
    }

    int shortestPath(int node1, int node2)
    {
        auto cmp = [](const pair<int, int> &p1, const pair<int, int> &p2)
        {
            return p1.first > p2.first || (p1.first == p2.first && p1.second < p2.second);
        };
        priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(cmp)> pq(cmp);
        pq.push({0, node1});
        unordered_map<int, int> visited = {{node1, 0}};
        while (pq.size())
        {
            auto cur_p = pq.top();
            pq.pop();
            auto cur_cost = cur_p.first, cur = cur_p.second;
            if (cur == node2)
                return cur_cost;
            for (auto nex_p : adj_lists[cur])
            {
                auto nex = nex_p.first, d = nex_p.second;
                auto new_cost = cur_cost + d;
                if (visited.find(nex) == visited.end() || new_cost < visited[nex])
                {
                    visited[nex] = new_cost;
                    pq.push({new_cost, nex});
                }
            }
        }
        return -1;
    }
};

/**
 * Your Graph object will be instantiated and called as such:
 * Graph* obj = new Graph(n, edges);
 * obj->addEdge(edge);
 * int param_2 = obj->shortestPath(node1,node2);
 */