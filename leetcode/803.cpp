class Pos {
public:
    int i, j;

    Pos () {
        i = j = 0;
    }

    Pos (int _i, int _j) {
        this->i = _i;
        this->j = _j;
    }

    Pos (vector<int> &v) {
        assert (v.size() == 2);
        this->i = v[0];
        this->j = v[1];
    }

    static bool is_valid(vector<vector<int>> &grid, int i, int j) {
        return (i >= 0 && i < grid.size() && j >= 0 && j < grid[i].size());
    }

    static bool check_value(int x) {
        return x != 0;
    }

    vector<Pos> get_valid_neighbors(vector<vector<int>> &grid) {
        static vector<vector<int>> dirs = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
        // static vector<vector<int>> dirs = {{0, 1}, {0, -1}, {1, 0}};

        vector<Pos> ret;
        for(auto &v : dirs) {
            int new_i = this->i + v[0], new_j = this->j + v[1];
            if(is_valid(grid, new_i, new_j) && check_value(grid[new_i][new_j])) {
                ret.push_back(Pos(new_i, new_j));
            }
        }
        return ret;
    }

    int count_valid_neighbors(vector<vector<int>> &grid) {
        static vector<vector<int>> dirs = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
        // static vector<vector<int>> dirs = {{0, 1}, {0, -1}, {1, 0}};

        int count = 0;
        for(auto &v : dirs) {
            int new_i = this->i + v[0], new_j = this->j + v[1];
            if(is_valid(grid, new_i, new_j) && check_value(grid[new_i][new_j])) {
                ++count;
            }
        }
        return count;
    }

    bool operator==(const Pos &other) const {
        return (this->i == other.i && this->j == other.j);
    }

    bool operator!=(const Pos &other) const {
        return !(*this == other);
    }

    bool operator<(const Pos &other) const {
        return (this->i < other.i || (this->i == other.i && this->j < other.j));
    }

    bool operator>(const Pos &other) const {
        return !((*this < other) || (*this == other));
    }


};

class MyHash {
public:
    size_t operator()(const Pos &p) const {
        int i = p.i, j = p.j;
        if(i < 0) i = ~i;
        return (i << 16) ^ j;
    }
};

typedef unordered_set<Pos, MyHash> POS_SET;
typedef unordered_map<Pos, Pos, MyHash> POS_MAP_POS;
typedef unordered_map<Pos, int, MyHash> POS_MAP_INT;

class Solution {
public:

    void assign_value(vector<vector<int>>& grid, Pos p, int val) {
        grid[p.i][p.j] = val;
    }

    int get_value(vector<vector<int>>& grid, Pos p) {
        return grid[p.i][p.j];
    }

    void init_top(vector<vector<int>>& grid, POS_MAP_POS &parent, POS_MAP_INT &group_count, Pos &top) {
        parent[top] = top;

        for(int i = 0, j = 0; j < grid[i].size(); ++j) {
            if(grid[i][j] == 1) {
                Pos cur(i,j);
                bfs(grid, cur, top, parent, group_count);
            }
        }

        group_count[top] = parent.size()-1; // minus -1,-1
        return ;
    }

    void bfs(vector<vector<int>>& grid, Pos &start, Pos &start_group, POS_MAP_POS &parent, POS_MAP_INT &group_count) {
        parent[start] = start_group;
        queue<Pos> q;
        q.push(start);

        while(q.size()) {
            Pos cur = q.front();
            q.pop();

            for(Pos &n : cur.get_valid_neighbors(grid)) {
                if(parent.find(n) == parent.end()) {
                    q.push(n);
                    parent[n] = start_group;
                    ++group_count[start_group];
                }
            }
        }
        return ;
    }

    void init_groups(vector<vector<int>> &grid, POS_MAP_POS &parent, POS_MAP_INT &group_count) {
        Pos cur(0,0);
        for(int i = 0; i < grid.size(); ++i) {
            cur.i = i;
            for(int j = 0; j < grid[i].size(); ++j) {
                cur.j = j;
                if(grid[i][j] && parent.find(cur) == parent.end()) {
                    parent[cur] = cur;
                    group_count[cur] = 1;
                    bfs(grid, cur, cur, parent, group_count);
                }
            }
        }
    }

    void merge_group(Pos &cur, Pos &neigh, POS_MAP_POS &parent, POS_MAP_INT &group_count) {
        Pos cur_group = find_group(cur, parent);
        Pos neigh_group = find_group(neigh, parent);

        if(cur_group < neigh_group) {
            parent[neigh_group] = cur_group;
            group_count[cur_group] += group_count[neigh_group];
            group_count.erase(neigh_group);
        }
        else if(cur_group > neigh_group) {
            parent[cur_group] = neigh_group;
            group_count[neigh_group] += group_count[cur_group];
            group_count.erase(cur_group);
        }
    }

    Pos find_group(Pos &cur, POS_MAP_POS &parent) {
        Pos group = parent[cur];
        if(group != cur)
            group = find_group(group, parent);
        parent[cur] = group;
        return group;
    }

    vector<int> hitBricks(vector<vector<int>>& grid, vector<vector<int>> &hits) {
        // remove all bricks in hits, add them back later
        // clear the 0 hit, set hit bricks to 0
        for(auto &v : hits) {
            int i = v[0], j = v[1];
            if(grid[i][j]) {
                grid[i][j] = 0;
            }
            else {
                v.clear();
            }
        }

        // reverse hits
        reverse(hits.begin(), hits.end());

        // set bricks connected to top to group Pos(-1, -1)
        Pos top_pos(-1, -1);
        POS_MAP_POS parent;
        POS_MAP_INT group_count;
        init_top(grid, parent, group_count, top_pos);

        // assign rest of the bricks to their group
        init_groups(grid, parent, group_count);

        vector<int> ans;
        for(auto &v : hits) {
            if(v.empty()) {
                ans.push_back(0);
            }
            else {
                Pos cur(v);
                assign_value(grid, cur, 1);

                int prev_count = group_count[top_pos];
                if(cur.i == 0)  {
                    parent[cur] = top_pos;
                    ++group_count[top_pos];
                }
                else {
                    parent[cur] = cur;
                    group_count[cur] = 1;
                }

                // merge self group with 4-neigh
                for(Pos &neigh : cur.get_valid_neighbors(grid))
                    merge_group(cur, neigh, parent, group_count);

                int diff = group_count[top_pos] - prev_count;
                if(diff > 0) --diff;
                ans.push_back(diff);
            }
        }

        reverse(ans.begin(), ans.end());
        return ans;
    }
};