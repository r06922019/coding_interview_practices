class State
{
public:
    int cur, visited, cost;
    State(int _i, int _v, int _c)
    {
        cur = _i;
        visited = _v;
        cost = _c;
    }
};

class Solution
{
public:
    const int INF = (1 << 12) * 12 + 1;

    int shortestPathLength(vector<vector<int> > &graph)
    {
        int n = graph.size();
        int full_visited = (1 << n) - 1;
        queue<State> q;
        vector<vector<int> > dp(n, vector<int>(1 << n, INF));
        for (int i = 0; i < n; ++i)
        {
            q.push(State(i, full_visited, 0));
            dp[i][full_visited] = 0;
        }

        while (q.size())
        {
            auto front = q.front();
            q.pop();
            int cur = front.cur, visited = front.visited, cost = front.cost;
            if (visited == (1 << cur))
            {
                continue; // stop branching
            }
            int prev_visited = visited & ~(1 << cur), prev_cost = cost + 1;
            for (auto next : graph[cur])
            {
                if (dp[next][prev_visited] > prev_cost)
                {
                    dp[next][prev_visited] = prev_cost;
                    q.push(State(next, prev_visited, prev_cost));
                }
            }
        }

        int ans = INF;
        for (int i = 0; i < n; ++i)
        {
            // printf("dp[%d][1 << i] = %d\n", i, dp[i][1 << i]);
            ans = min(ans, dp[i][1 << i]);
        }
        return ans;
    }
};