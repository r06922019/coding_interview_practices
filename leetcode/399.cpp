class Solution
{
public:
#define U_S_S_D unordered_map<string, unordered_map<string, double> >
    U_S_S_D make_graph(vector<vector<string> > &equations, vector<double> &values)
    {
        U_S_S_D graph;
        for (int i = 0, n = equations.size(); i < n; ++i)
        {
            const auto &eq = equations[i];
            const auto &val = values[i];
            graph[eq[0]][eq[1]] = val;
            graph[eq[1]][eq[0]] = 1 / val;
        }
        return graph;
    }

    double solve(U_S_S_D &graph, const string &a, const string &b)
    {
        unordered_set<string> visited;
        stack<pair<string, double> > st;

        if (graph.find(a) == graph.end() || graph.find(b) == graph.end())
            return -1;
        visited.insert(a);
        st.push({a, 1});
        while (st.size())
        {
            auto top = st.top();
            st.pop();
            auto cur_node = top.first;
            auto cur_ans = top.second;
            if (cur_node == b)
                return cur_ans;
            for (auto next_p : graph[cur_node])
            {
                auto next = next_p.first;
                auto edge_weight = next_p.second;
                if (visited.find(next) == visited.end())
                {
                    visited.insert(next);
                    st.push({next, cur_ans * edge_weight});
                }
            }
        }
        return -1;
    }

    vector<double> calcEquation(vector<vector<string> > &equations, vector<double> &values, vector<vector<string> > &queries)
    {
        U_S_S_D graph = make_graph(equations, values);
        vector<double> ans;
        for (const auto &q : queries)
        {
            ans.push_back(solve(graph, q[0], q[1]));
        }
        return ans;
    }
};