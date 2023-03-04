class PairHash
{
public:
    size_t operator()(const pair<int, int> &p) const
    {
        return p.first + ((p.second & 0x7FFF) << 15);
    }
};
typedef unordered_set<pair<int, int>, PairHash> PAIR_SET;

class Solution
{
public:
    unordered_map<int, vector<int>> make_adj_lists(vector<vector<int>> &edges)
    {
        unordered_map<int, vector<int>> adj_lists;
        for (auto e : edges)
        {
            const int a = e[0], b = e[1];
            adj_lists[a].push_back(b);
            adj_lists[b].push_back(a);
        }
        return adj_lists;
    }

    PAIR_SET make_guess_set(vector<vector<int>> &guesses)
    {
        PAIR_SET guess_set;
        for (auto g : guesses)
        {
            guess_set.insert({g[0], g[1]});
        }
        return guess_set;
    }

    int get_ans0(int n, unordered_map<int, vector<int>> &adj_lists, PAIR_SET &guess_set)
    {
        int ans = 0;
        stack<int> st;
        vector<bool> visited(n, false);
        st.push(0);
        visited[0] = true;
        while (st.size())
        {
            auto cur = st.top();
            st.pop();
            for (auto nex : adj_lists[cur])
            {
                if (!visited[nex])
                {
                    ans += guess_set.count({cur, nex});
                    visited[nex] = true;
                    st.push(nex);
                }
            }
        }
        return ans;
    }

    int rootCount(vector<vector<int>> &edges, vector<vector<int>> &guesses, int k)
    {
        const int n = edges.size() + 1;
        unordered_map<int, vector<int>> adj_lists = make_adj_lists(edges);
        PAIR_SET guess_set = make_guess_set(guesses);

        stack<pair<int, int>> st;
        vector<bool> visited(n, false);
        int cur_ans = get_ans0(n, adj_lists, guess_set);
        int ans = 0;

        st.push({0, cur_ans});
        visited[0] = true;

        while (st.size())
        {
            auto cur_status = st.top();
            st.pop();
            auto cur_node = cur_status.first, cur_ans = cur_status.second;
            if (cur_ans >= k)
                ++ans;
            for (auto nex : adj_lists[cur_node])
            {
                if (!visited[nex])
                {
                    visited[nex] = true;
                    st.push({nex, cur_ans - guess_set.count({cur_node, nex}) + guess_set.count({
                        nex, cur_node})});
                }
            }
        }
        return ans;
    }
};