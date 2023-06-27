class Solution
{
public:
    int dfs(unordered_map<int, vector<int>> &adj, int start, int n)
    {
        vector<bool> visited(n, false);
        stack<int> st;
        visited[start] = true;
        st.push(start);
        while (st.size())
        {
            auto cur = st.top();
            st.pop();
            for (auto nex : adj[cur])
            {
                if (!visited[nex])
                {
                    visited[nex] = true;
                    st.push(nex);
                }
            }
        }

        int cnt = 0;
        for (auto x : visited)
            if (x)
                ++cnt;
        return cnt;
    }

    int maximumDetonation(vector<vector<int>> &bombs)
    {
        const int n = bombs.size();
        unordered_map<int, vector<int>> adj;
        for (int i = 0; i < n; ++i)
        {
            for (int j = i + 1; j < n; ++j)
            {
                const long long d_2 = pow(bombs[i][0] - bombs[j][0], 2) + pow(bombs[i][1] - bombs[j][1], 2);
                if (d_2 <= pow((long long)bombs[i][2], 2))
                {
                    adj[i].push_back(j);
                }
                if (d_2 <= pow((long long)bombs[j][2], 2))
                {
                    adj[j].push_back(i);
                }
            }
        }

        int ans = 0;
        for (int i = 0; i < n; ++i)
        {
            ans = max(ans, dfs(adj, i, n));
        }
        return ans;
    }
};