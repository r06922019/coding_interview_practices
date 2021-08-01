class PairHash {
public:
    size_t operator()(const pair<int, int> &p) const {
        return p.first ^ p.second;
    }
};

class Solution {
public:

    vector<vector<int>> dirs = {
        {0,1}, {0,-1},
        {1,0}, {-1,0}
    };

    bool is_valid(vector<vector<int>>& grid, int i, int j) {
        return i >= 0 && i < grid.size() && j >= 0 && j < grid[i].size();
    }

    void dfs1(vector<vector<int>>& grid, int i, int j, const int group) {
        stack<pair<int, int>> st;
        grid[i][j] = group;
        st.push({i,j});
        while(st.size()) {
            auto top = st.top();
            st.pop();
            for(auto &dir : dirs) {
                int new_i = top.first+dir[0];
                int new_j = top.second+dir[1];
                if(is_valid(grid, new_i, new_j) && grid[new_i][new_j] == 1) {
                    st.push({new_i,new_j});
                    grid[new_i][new_j] = group;
                }
            }
        }
    }

    int dfs2(vector<vector<int>>& grid2, int i, int j, vector<vector<int>>& grid1) {
        stack<pair<int, int>> st;
        unordered_set<int> groups_seen;
        st.push({i,j});
        grid2[i][j] = 0;
        groups_seen.insert(grid1[i][j]);
        while(st.size()) {
            auto top = st.top();
            st.pop();
            for(auto &dir : dirs) {
                int new_i = top.first+dir[0];
                int new_j = top.second+dir[1];
                if(is_valid(grid2, new_i, new_j) && grid2[new_i][new_j] == 1) {
                    st.push({new_i,new_j});
                    grid2[new_i][new_j] = 0;
                    groups_seen.insert(grid1[new_i][new_j]);
                }
            }
        }
        return (groups_seen.size() == 1 && *groups_seen.begin() != 0)? 1:0;
    }

    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        int m = grid1.size(), n = grid1[0].size();
        int group = 2;
        for(int i = 0; i < m; ++i) {
            for(int j = 0; j < n; ++j) {
                if(grid1[i][j] == 1) {
                    // printf("starting at %d %d with group = %d\n", i, j, group);
                    dfs1(grid1, i, j, group);
                    ++group;
                }
            }
        }
        printf("group %d\n", group);

        int cnt = 0;
        for(int i = 0; i < m; ++i) {
            for(int j = 0; j < n; ++j) {
                if(grid2[i][j] == 1) {
                    // printf("starting at %d %d\n", i, j);
                    cnt += dfs2(grid2, i, j, grid1);
                    // printf("cnt = %d\n", cnt);
                }
            }
        }
        return cnt;
    }
};