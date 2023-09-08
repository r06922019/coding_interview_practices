class Solution
{
public:
    void dfs(int cur, int target, vector<vector<int>> &graph, vector<int> &buf, vector<vector<int>> &ans)
    {
        if (cur == target)
        {
            ans.push_back(buf);
            return;
        }
        for (auto neigh : graph[cur])
        {
            if (find(buf.begin(), buf.end(), neigh) == buf.end())
            {
                buf.push_back(neigh);
                dfs(neigh, target, graph, buf, ans);
                buf.pop_back();
            }
        }
    }

    vector<vector<int>> allPathsSourceTarget(vector<vector<int>> &graph)
    {
        vector<vector<int>> ans;
        vector<int> buf = {0};
        auto n = graph.size();
        dfs(0, n - 1, graph, buf, ans);
        return ans;
    }
};