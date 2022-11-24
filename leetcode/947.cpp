class Solution
{
public:
    void dfs(int start, unordered_map<int, unordered_set<int>> &adj_lists, unordered_set<int> &visited)
    {

        stack<int> st;
        visited.insert(start);
        st.push(start);
        while (st.size())
        {
            auto cur = st.top();
            st.pop();
            for (auto nxt : adj_lists[cur])
            {
                if (visited.find(nxt) == visited.end())
                {
                    visited.insert(nxt);
                    st.push(nxt);
                }
            }
        }
    }

    int removeStones(vector<vector<int>> &stones)
    {
        unordered_map<int, unordered_set<int>> x_set, y_set, adj_lists;
        int n = stones.size();
        for (int i = 0; i < n; ++i)
        {
            const auto x = stones[i][0], y = stones[i][1];
            x_set[x].insert(i);
            y_set[y].insert(i);
        }
        for (int i = 0; i < n; ++i)
        {
            const auto x = stones[i][0], y = stones[i][1];
            adj_lists[i].insert(x_set[x].begin(), x_set[x].end());
            adj_lists[i].insert(y_set[y].begin(), y_set[y].end());
        }

        int count = 0;
        unordered_set<int> visited;
        for (int i = 0; i < n; ++i)
        {
            if (visited.find(i) == visited.end())
            {
                ++count;
                dfs(i, adj_lists, visited);
            }
        }
        return n - count;
    }
};