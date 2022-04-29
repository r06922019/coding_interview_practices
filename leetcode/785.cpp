class Solution
{
public:
    bool isBipartite(vector<vector<int> > &adj_list)
    {
        unordered_map<int, int> colors;
        stack<int> st;
        for (int i = 0, n = adj_list.size(); i < n; ++i)
        {
            if (colors.find(i) != colors.end())
                continue;
            st.push(i);
            colors[i] = 0;
            while (st.size())
            {
                auto cur = st.top();
                st.pop();
                int cur_color = colors[cur];
                int next_color = cur_color ^ 1;
                for (auto next : adj_list[cur])
                {
                    if (colors.find(next) == colors.end())
                    {
                        colors[next] = next_color;
                        st.push(next);
                    }
                    else
                    {
                        if (colors[next] != next_color)
                            return false;
                    }
                }
            }
        }
        return true;
    }
};