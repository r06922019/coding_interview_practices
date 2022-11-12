class Solution
{
public:
    void dfs(int prev, int cur,
             unordered_map<int, vector<int>> &adj_lists,
             vector<int> &amount,
             int cost,
             int &ans)
    {
        cost += amount[cur];
        if (adj_lists[cur].size() == 1 && adj_lists[cur][0] == prev)
        {
            ans = max(ans, cost);
            return;
        }

        for (auto next : adj_lists[cur])
        {
            if (next != prev)
            {
                dfs(cur, next, adj_lists, amount, cost, ans);
            }
        }
    }

    void adjust_amounts(unordered_map<int, vector<int>> &adj_lists, int bob, vector<int> &amount)
    {
        queue<int> q;
        q.push(0);
        unordered_map<int, int> prevs = {{0, 0}};
        while (q.size())
        {
            auto cur = q.front();
            q.pop();
            if (cur == bob)
            {
                vector<int> path;
                while (cur != 0)
                {
                    path.push_back(cur);
                    cur = prevs[cur];
                }
                path.push_back(0);
                for (int i = 0; i < path.size() / 2; ++i)
                {
                    amount[path[i]] = 0;
                }
                if (path.size() % 2 == 1)
                {
                    amount[path[path.size() / 2]] /= 2;
                }
                return;
            }
            for (auto next : adj_lists[cur])
            {
                if (next != prevs[cur])
                {
                    prevs[next] = cur;
                    q.push(next);
                }
            }
        }
    }

    int mostProfitablePath(vector<vector<int>> &edges, int bob, vector<int> &amount)
    {
        unordered_map<int, vector<int>> adj_lists;
        for (auto e : edges)
        {
            adj_lists[e[0]].push_back(e[1]);
            adj_lists[e[1]].push_back(e[0]);
        }
        adjust_amounts(adj_lists, bob, amount);
        int ans = INT_MIN;
        dfs(-1, 0, adj_lists, amount, 0, ans);
        return ans;
    }
};