class VectorHash {
public:
    size_t operator()(const vector<int> &vec) const {
        size_t ret = 0;
        for(auto &num : vec) {
            ret = (ret << 4) ^ num;
        }
        return ret;
    }
};

typedef unordered_set<vector<int>, VectorHash> POINT_SET;

class Solution {
public:
    vector<vector<int>> dirs = {
        {0, 1},
        {0, -1},
        {1, 0},
        {-1, 0}
    };

    bool is_valid(vector<vector<int>> &heights, int i, int j) {
        return i >= 0 && i < heights.size() && j >= 0 && j < heights[i].size();
    }

    void bfs(vector<vector<int>> &heights, POINT_SET &init_set, POINT_SET &visited) {
        queue<vector<int>> qu;
        for(auto &p : init_set) {
            qu.push(p);
        }

        while(qu.size()) {
            int qu_size = qu.size();
            while(qu_size--) {
                auto p = qu.front();
                qu.pop();
                for(auto &dir : dirs) {
                    if(is_valid(heights, p[0] + dir[0], p[1] + dir[1])) {
                        vector<int> new_p = {p[0] + dir[0], p[1] + dir[1]};
                        if(visited.find(new_p) == visited.end() &&
                           heights[p[0]][p[1]] <= heights[new_p[0]][new_p[1]]) {
                            visited.insert(new_p);
                            qu.push(new_p);
                        }
                    }
                }
            }
        }
    }

    void fill_in(vector<vector<int>> &heights, POINT_SET &s, int val) {
        for(auto &p : s) {
            heights[p[0]][p[1]] = val;
        }
    }

    vector<vector<int>> add_border(vector<vector<int>>& _heights) {
        int m = _heights.size(), n = _heights[0].size();
        vector<vector<int>> heights(m+2, vector<int>(n+2, 0));

        for(int i = 1; i <= m; ++i) {
            for(int j = 1; j <= n; ++j) {
                heights[i][j] = _heights[i-1][j-1];
            }
        }
        return heights;
    }

    POINT_SET get_pacific_set(vector<vector<int>> &heights) {
        int m = heights.size(), n = heights[0].size();
        POINT_SET s;
        for(int j = 0; j < n; ++j) {
            s.insert({0, j});
        }
        for(int i = 1; i < m-1; ++i) {
            s.insert({i, 0});
        }
        return s;
    }

    POINT_SET get_atlantic_set(vector<vector<int>> &heights) {
        int m = heights.size(), n = heights[0].size();
        POINT_SET s;
        for(int j = 0; j < n; ++j) {
            s.insert({m-1, j});
        }
        for(int i = 1; i < m-1; ++i) {
            s.insert({i, n-1});
        }
        return s;
    }

    vector<vector<int>> pacificAtlantic(vector<vector<int>>& _heights) {
        // enlarge the map
        vector<vector<int>> heights = add_border(_heights);

        POINT_SET atlantic_set = get_atlantic_set(heights);
        POINT_SET pacific_set = get_pacific_set(heights);

        // pacific all -1, altantic all 0
        fill_in(heights, atlantic_set, 0);
        fill_in(heights, pacific_set, -1);
        // start bfs on all altantic
        POINT_SET atlantic_visited = atlantic_set;
        bfs(heights, atlantic_visited, atlantic_visited);

        // pacific all -1, altantic all 0
        fill_in(heights, atlantic_set, -1);
        fill_in(heights, pacific_set, 0);
        // start bfs on all altantic
        POINT_SET pacific_visited = pacific_set;
        bfs(heights, pacific_visited, pacific_visited);

        // get intersection of sets
        vector<vector<int>> ans;
        for(auto &p : pacific_visited) {
            if(atlantic_visited.find(p) != atlantic_visited.end()) {
                ans.push_back({p[0]-1, p[1]-1});
            }
        }
        return ans;
    }
};