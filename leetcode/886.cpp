class Solution
{
public:
    bool possibleBipartition(int n, vector<vector<int>> &dislikes)
    {
        unordered_map<int, vector<int>> adj_lists;
        for (auto v : dislikes)
        {
            auto a = v[0], b = v[1];
            adj_lists[a - 1].push_back(b - 1);
            adj_lists[b - 1].push_back(a - 1);
        }
        stack<int> st;
        unordered_map<int, int> index_to_colors;
        for (int i = 0; i < n; ++i)
        {
            if (index_to_colors.find(i) != index_to_colors.end())
            {
                continue;
            }
            st.push(i), index_to_colors[i] = 0;
            while (st.size())
            {
                auto cur = st.top();
                st.pop();
                for (auto neigh : adj_lists[cur])
                {
                    if (index_to_colors.find(neigh) == index_to_colors.end())
                    {
                        index_to_colors[neigh] = index_to_colors[cur] ^ 1;
                        st.push(neigh);
                    }
                    else if (index_to_colors[neigh] == index_to_colors[cur])
                    {
                        return false;
                    }
                }
            }
        }
        return true;
    }
};