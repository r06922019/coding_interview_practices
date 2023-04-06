class Solution
{
public:
    int minReorder(int n, vector<vector<int>> &connections)
    {
        unordered_map<int, unordered_map<int, int>> adj_sets;
        for (const auto &conn : connections)
        {
            adj_sets[conn[1]][conn[0]] = 0;
            adj_sets[conn[0]][conn[1]] = 1;
        }

        int ans = 0;
        stack<int> st;
        unordered_set<int> visited;
        st.push(0);
        visited.insert(0);
        while (st.size())
        {
            auto cur = st.top();
            st.pop();
            for (const auto &it : adj_sets[cur])
            {
                const auto nex = it.first;
                const auto cost = it.second;
                if (visited.find(nex) == visited.end())
                {
                    st.push(nex);
                    visited.insert(nex);
                    ans += cost;
                }
            }
        }
        return ans;
    }
};