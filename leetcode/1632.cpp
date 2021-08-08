class Solution {
public:

    vector<int> dfs(int k,
                    unordered_set<int> &visited,
                    unordered_map<int, vector<int>> &adj_lists) {
        vector<int> group;
        stack<int> st;

        st.push(k);
        visited.insert(k);
        group.push_back(k);
        while(st.size()) {
            int top = st.top();
            st.pop();
            for(auto next : adj_lists[top]) {
                if(visited.find(next) == visited.end()) {
                    st.push(next);
                    visited.insert(next);
                    group.push_back(next);
                }
            }
        }
        return group;
    }

    void add_edge(unordered_map<int, vector<int>> &adj_lists, int a, int b) {
        adj_lists[a].push_back(b);
        adj_lists[b].push_back(a);
    }

    vector<vector<int>> group_with_dfs(vector<vector<int>> &nums_pos,
                                       int start, int end,
                                       int m, int n) {
        vector<int> row_groups(m, -1), col_groups(n, -1);
        unordered_map<int, vector<int>> adj_lists;
        for(int k = start; k < end; ++k) {
            int i = nums_pos[k][1];
            int j = nums_pos[k][2];
            if(row_groups[i] == -1) {
                row_groups[i] = k;
            }
            else {
                add_edge(adj_lists, row_groups[i], k);
            }
            if(col_groups[j] == -1) {
                col_groups[j] = k;
            }
            else {
                add_edge(adj_lists, col_groups[j], k);
            }
        }

        unordered_set<int> visited;
        vector<vector<int>> groups;
        for(int k = start; k < end; ++k) {
            if(visited.find(k) == visited.end()) {
                vector<int> group = dfs(k, visited, adj_lists);
                groups.push_back(group);
            }
        }
        return groups;
    }

    int get_parent(vector<int> &parent, int x) {
        if(parent[x] != x) {
            parent[x] = get_parent(parent, parent[x]);
        }
        return parent[x];
    }

    void merge_group(vector<int> &parent, int x, int y) {
        int x_parent = get_parent(parent, x);
        int y_parent = get_parent(parent, y);
        parent[y_parent] = x_parent;
    }

    unordered_map<int, vector<int>> group_with_uf(vector<vector<int>> &nums_pos,
                                        vector<int> &parent,
                                       int start, int end,
                                       int m, int n) {
        vector<int> row_groups(m, -1), col_groups(n, -1);
        for(int k = start; k < end; ++k) {
            int i = nums_pos[k][1];
            int j = nums_pos[k][2];
            if(row_groups[i] == -1) {
                row_groups[i] = k;
            }
            else {
                merge_group(parent, row_groups[i], k);
            }
            if(col_groups[j] == -1) {
                col_groups[j] = k;
            }
            else {
                merge_group(parent, col_groups[j], k);
            }
        }
        unordered_map<int, vector<int>> group_to_members;
        for(int k = start; k < end; ++k) {
            group_to_members[ get_parent(parent, k) ].push_back(k);
        }
        return group_to_members;
    }

    vector<vector<int>> matrixRankTransform(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        vector<int> row_max(m, 0), col_max(n, 0);
        vector<vector<int>> nums_pos, ans(m, vector<int>(n, 0));
        for(int i = 0; i < m; ++i) {
            for(int j = 0; j < n; ++j) {
                nums_pos.push_back({matrix[i][j], i, j});
            }
        }
        sort(nums_pos.begin(), nums_pos.end());
        vector<int> parent(nums_pos.size(), 0);
        for(int k = 0; k < nums_pos.size(); ++k) {
            parent[k] = k;
        }
        int index = 0;
        while(index < nums_pos.size()) {
            int num = nums_pos[index][0];
            int new_index = index;
            while(new_index < nums_pos.size()
                  && nums_pos[new_index][0] == num) {
                ++new_index;
            }
            unordered_map<int, vector<int>> groups = group_with_uf(nums_pos, parent, index, new_index, m, n);
            for(const auto &p : groups) {
                const auto &group = p.second;
                int rank = 0;
                for(const auto &k : group) {
                    int i = nums_pos[k][1];
                    int j = nums_pos[k][2];
                    rank = max(rank, max(row_max[i], col_max[j]));
                }
                ++rank;
                for(const auto &k : group) {
                    int i = nums_pos[k][1];
                    int j = nums_pos[k][2];
                    ans[i][j] = row_max[i] = col_max[j] = rank;
                }
            }
            index = new_index;
        }
        return ans;
    }
};