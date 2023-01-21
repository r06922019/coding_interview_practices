class Solution
{
public:
    unordered_map<int, vector<int>> make_adj_lists(const int &n, vector<vector<int>> &edges)
    {
        unordered_map<int, vector<int>> adj_lists;
        for (auto e : edges)
        {
            int a = e[0], b = e[1];
            adj_lists[a].push_back(b);
            adj_lists[b].push_back(a);
        }
        return adj_lists;
    }
    bool validPath(int n, vector<vector<int>> &edges, int source, int destination)
    {
        unordered_map<int, vector<int>> adj_lists = make_adj_lists(n, edges);

        stack<int> st;
        unordered_set<int> visited;
        st.push(source);
        visited.insert(source);
        while (st.size())
        {
            auto cur = st.top();
            if (cur == destination)
                return true;
            st.pop();
            for (auto neigh : adj_lists[cur])
            {
                if (visited.find(neigh) == visited.end())
                {
                    visited.insert(neigh);
                    st.push(neigh);
                }
            }
        }
        return false;
    }
};