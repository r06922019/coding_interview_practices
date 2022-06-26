class Solution
{
public:
    long long maximumImportance(int n, vector<vector<int> > &roads)
    {
        unordered_map<int, vector<int> > adj_list;
        for (auto road : roads)
        {
            int a = road[0], b = road[1];
            adj_list[a].push_back(b);
            adj_list[b].push_back(a);
        }

        vector<int> nodes;
        for (int i = 0; i < n; ++i)
        {
            nodes.push_back(i);
        }

        sort(nodes.begin(), nodes.end(), [&adj_list](const int &a, const int &b)
             { return adj_list[a].size() > adj_list[b].size(); });

        long long ans = 0;
        for (int i = 0; i < n; ++i)
        {
            ans += adj_list[nodes[i]].size() * (long long)(n - i);
        }
        return ans;
    }
};