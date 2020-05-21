class Pos {
public:
    int i, j;
    Pos () {
        i = j = 0;
    }

    Pos (int _i, int _j) {
        i = _i;
        j = _j;
    }

    Pos add_vec(vector<int> &v) {
        assert(v.size() == 2);
        Pos p = *this;
        p.i += v[0];
        p.j += v[1];
        return p;
    }

    string to_str() {
        return "(" + to_string(i) + "," + to_string(j) + ")";
    }

    bool is_valid(vector<vector<int>> &grid) {
        return i >= 0 && i < grid.size() && j >= 0 && j < grid[i].size();
    }

    bool operator==(const Pos &other) const {
        return this->i == other.i && this->j == other.j;
    }

    bool operator!=(const Pos &other) const {
        return !(*this == other);
    }

    int get_index1d(vector<vector<int>> &grid) const {
        return i * grid[0].size() + j;
    }

    vector<Pos> get_neighbors(vector<vector<int>> &grid) {
        static vector<vector<int>> dirs = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

        vector<Pos> ret;
        for(auto &dir : dirs) {
            Pos p = this->add_vec(dir);
            if(p.is_valid(grid))
                ret.push_back(p);
        }
        return ret;
    }
};

class MyHash {
public:
    size_t operator()(const Pos &p) const {
        return (p.i << 16) ^ p.j;
    }
};

typedef unordered_set<Pos, MyHash> POS_SET;
typedef unordered_map<Pos, Pos, MyHash> POS_MAP_POS;
typedef unordered_map<Pos, unordered_map<int, int>, MyHash> DP_MEM;

class Solution {
public:
    DP_MEM dp;
    int convert_state(POS_SET &s, vector<vector<int>> &grid) {
        int state = 0;
        for(auto &p : s) {
            int index_1d = p.get_index1d(grid);
            state |= (1 << index_1d);
        }
        return state;
    }

    // print paths!
    int uniquePathsIII(vector<vector<int>>& grid) {
        Pos start, target;
        POS_SET cells_to_visit;
        for(int i = 0; i < grid.size(); ++i) {
            for(int j = 0; j < grid[i].size(); ++j) {
                if(grid[i][j] == 1) { // (starting cell)
                    start = Pos(i, j);
                }
                else if(grid[i][j] == 2) { // (target cell)
                    target = Pos(i, j);
                }
                else if(grid[i][j] == 0) {
                    // non obstacle
                    cells_to_visit.insert(Pos(i, j));
                }
            }
        }
        cells_to_visit.insert(target);
        POS_MAP_POS parent;
        parent[start] = start;
        int ans = 0;
        helper(start, target, grid, cells_to_visit, parent, ans);
        return ans;
    }

    void print_path(Pos p, POS_MAP_POS &parent) {
        string s = "";
        while(parent[p] != p) {
            s = p.to_str() + " " + s;
            p = parent[p];
        }
        s = p.to_str() + " " + s;
        cout << s << endl;
    }

    void helper(Pos &current, Pos &target, vector<vector<int>>& grid, POS_SET &cells_to_visit, POS_MAP_POS &parent, int &ans) {
        // dp[P][convert_state(s)]
        int state = convert_state(cells_to_visit, grid);
        if(dp.find(current) != dp.end()) {
            unordered_map<int, int> &sparse_table = dp[current];
            if(sparse_table.find(state) != sparse_table.end()) {
                ans += sparse_table[state];
                return ;
            }
        }

        if(current == target) {
            if(cells_to_visit.empty()) {
                // print_path(current, parent);
                ++ans;
            }
            return ;
        }

        dp[current][state] = ans;
        // try to visit 4 neighbor of current cell
        for(Pos &p : current.get_neighbors(grid)) {
            if(cells_to_visit.find(p) != cells_to_visit.end()) {
                cells_to_visit.erase(p);
                parent[p] = current;
                helper(p, target, grid, cells_to_visit, parent, ans);
                cells_to_visit.insert(p);
                parent.erase(p);
            }
        }
        dp[current][state] = ans - dp[current][state];
        return ;
    }
};
