class Solution
{
public:
    /*
    unordered_map<int, vector<int>> make_adj_lists(vector<vector<int>> &roads) {
        unordered_map<int, vector<int>> adj_lists;
        for(auto v : roads) {
            adj_lists[v[0]].push_back(v[1]);
            adj_lists[v[1]].push_back(v[0]);
        }
        return adj_lists;
    }

    int minScore(int n, vector<vector<int>>& roads) {
        unordered_map<int, unordered_map<int, int>> costs;
        for(auto v : roads) {
            costs[v[0]][v[1]] = v[2];
            costs[v[1]][v[0]] = v[2];
        }

        unordered_map<int, vector<int>> adj_lists = make_adj_lists(roads);

        stack<int> st;
        unordered_set<int> visited;
        int ans = INT_MAX;
        st.push(n);
        visited.insert(n);
        while(st.size()) {
            auto cur = st.top();
            st.pop();
            for(auto nex : adj_lists[cur]) {
                ans = min(ans, costs[cur][nex]);
                if(visited.find(nex) == visited.end()) {
                    visited.insert(nex);
                    st.push(nex);
                }
            }
        }
        return ans;
    }*/

    int find_group(vector<int> &groups, int cur)
    {
        if (groups[cur] != cur)
        {
            groups[cur] = find_group(groups, groups[cur]);
        }
        return groups[cur];
    }

    int merge_groups(vector<int> &groups, int a, int b)
    {
        auto a_group = find_group(groups, a);
        auto b_group = find_group(groups, b);
        return groups[a_group] = groups[b_group] = max(a_group, b_group);
    }

    int minScore(int n, vector<vector<int>> &roads)
    {
        const int target = n - 1;
        for (auto &v : roads)
        {
            --v[0], --v[1];
        }

        vector<int> groups(n, 0), ans(n, INT_MAX);
        for (int i = 0; i < n; ++i)
            groups[i] = i;
        for (auto v : roads)
        {
            const int a = v[0], b = v[1], c = v[2];
            const auto ga = find_group(groups, a);
            const auto gb = find_group(groups, b);
            const auto x = merge_groups(groups, a, b);
            // printf("merged a %d b %d into x %d\n", a, b, x);
            ans[x] = min(ans[ga], ans[gb]);
            ans[x] = min(ans[x], c);
        }
        return ans[target];
    }
};