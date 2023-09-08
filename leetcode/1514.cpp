class Solution
{
public:
    double maxProbability(int n, vector<vector<int>> &edges, vector<double> &succProb, int start, int end)
    {
        unordered_map<int, vector<pair<int, double>>> adj_list;
        for (int i = 0; i < edges.size(); ++i)
        {
            const int a = edges[i][0], b = edges[i][1];
            adj_list[a].push_back({b, succProb[i]});
            adj_list[b].push_back({a, succProb[i]});
        }
        unordered_map<int, double> visited;
        queue<pair<int, double>> q;
        q.push({start, 1});
        while (q.size())
        {
            auto cur_p = q.front();
            q.pop();
            const int cur = cur_p.first;
            const double prob = cur_p.second;
            for (auto nex_p : adj_list[cur])
            {
                const int nex = nex_p.first;
                const double nex_prob = prob * nex_p.second;
                if (nex_prob > visited[nex])
                {
                    visited[nex] = nex_prob;
                    q.push({nex, nex_prob});
                }
            }
        }
        return visited[end];
    }
};