class Solution
{
public:
    void dfs(int start, unordered_map<int, vector<int> > &adj_lists, unordered_set<int> &visited)
    {
        stack<int> st;
        st.push(start);
        visited.insert(start);
        while (st.size())
        {
            auto cur = st.top();
            st.pop();
            for (auto next : adj_lists[cur])
            {
                if (visited.find(next) == visited.end())
                {
                    visited.insert(next);
                    st.push(next);
                }
            }
        }
    }

    long long countPairs(int n, vector<vector<int> > &edges)
    {
        long long ans = 0;
        unordered_set<int> global_visited;
        unordered_map<int, vector<int> > adj_lists;
        for (auto edge : edges)
        {
            int a = edge[0], b = edge[1];
            adj_lists[a].push_back(b);
            adj_lists[b].push_back(a);
        }
        for (int i = 0; i < n; ++i)
        {
            unordered_set<int> visited;
            if (global_visited.find(i) == global_visited.end())
            {
                dfs(i, adj_lists, visited);
                ans += (long long)(visited.size()) * (long long)(n - visited.size());
                for (auto x : visited)
                {
                    global_visited.insert(x);
                }
            }
        }
        return ans >> 1;
    }
};