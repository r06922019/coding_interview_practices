typedef vector<vector<char>> CHAR_GRID;
vector<vector<int>> dirs = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

class Pos {
public:
    int i, j;
    Pos() {
        i = j = 0;
    }

    Pos(int _i, int _j) {
        i = _i;
        j = _j;
    }

    Pos(vector<int> &v) {
        assert(v.size() == 2);
        i = v[0];
        j = v[1];
    }

    bool is_valid(CHAR_GRID &grid) {
        return i >= 0 && i < grid.size() && j >= 0 && j < grid[i].size();
    }

    Pos add_vec(vector<int> &v) {
        Pos p = *this;
        p.i += v[0];
        p.j += v[1];
        return p;
    }

    Pos minus_vec(vector<int> &v) {
        Pos p = *this;
        p.i -= v[0];
        p.j -= v[1];
        return p;
    }

    char get_value(CHAR_GRID &grid) {
        return grid[i][j];
    }

    void assign_val(CHAR_GRID &grid, char val) {
        grid[i][j] = val;
    }

    void print() const {
        printf("%d %d\n", i, j);
    }

    string str() const {
        return to_string(i) + " " + to_string(j);
    }

    vector<Pos> get_valid_neighbors(CHAR_GRID &grid) {
        vector<Pos> ret;
        for(auto &dir : dirs) {
            Pos n = this->add_vec(dir);
            if(n.is_valid(grid) && n.get_value(grid) != '#' && n.get_value(grid) != 'B') {
                ret.push_back(n);
            }
        }
        return ret;
    }

    bool operator==(const Pos &other) const {
        return i == other.i && j == other.j;
    }

    bool operator!=(const Pos &other) const {
        return !(*this == other);
    }
};

class PosHash {
public:
    size_t operator()(const Pos &p) const {
        return (p.i << 16) ^ p.j;
    }
};

typedef unordered_set<Pos, PosHash> POS_SET;

class PosPairHash {
public:
    size_t operator()(const pair<Pos, Pos> &p_pair) const {
        const Pos &p = p_pair.first, &q = p_pair.second;
        return ((p.i << 16) ^ p.j) ^ ((q.i << 16) ^ q.j);
    }
};

typedef unordered_set<pair<Pos, Pos>, PosPairHash> POS_PAIR_SET;

class Solution {
public:

    Pos find_in_grid(CHAR_GRID &grid, char target) {
        for(int i = 0; i < grid.size(); ++i) {
            for(int j = 0; j < grid[i].size(); ++j){
                if(grid[i][j] == target)
                    return Pos(i, j);
            }
        }
        return Pos();
    }

    bool dfs(CHAR_GRID &grid, Pos &start, Pos &target) {
        stack<Pos> s;
        POS_SET visited;

        s.push(start);
        visited.insert(start);
        while(s.size()) {
            Pos cur = s.top();
            s.pop();
            if(cur == target) return true;
            for(Pos &n : cur.get_valid_neighbors(grid)) {
                if(visited.find(n) == visited.end()) {
                    visited.insert(n);
                    s.push(n);
                }
            }
        }
        return false;
    }

    int bfs(CHAR_GRID &grid, Pos &box_start, Pos &person_start, Pos &target) {
        POS_PAIR_SET visited;
        queue<pair<Pos, Pos>> q;

        person_start.assign_val(grid, '.');
        box_start.assign_val(grid, '.');
        q.push({box_start, person_start});
        visited.insert({box_start, person_start});
        int moves = 0;
        while(q.size()) {
            // printf("moves:%d \n", moves);
            int q_n = q.size();
            while(q_n--) {
                pair<Pos, Pos> cur_p = q.front();
                q.pop();
                Pos &box_cur = cur_p.first, &person_cur = cur_p.second;
                if(box_cur == target) return moves;
                for(auto &dir : dirs) {
                    Pos box_next = box_cur.add_vec(dir), person_next = box_cur.minus_vec(dir);
                    if(box_next.is_valid(grid) && box_next.get_value(grid) != '#'){
                        // try if we can reach b from person_cur
                        box_cur.assign_val(grid, '#');
                        bool person_next_reachable = dfs(grid, person_cur, person_next);
                        // cout << "try from " << person_cur.str() << " to " << person_next.str() << " to push box " << box_cur.str() << " " << person_next_reachable <<  endl;
                        box_cur.assign_val(grid, '.');

                        if(person_next_reachable && visited.find({box_next, person_next}) == visited.end()) {
                            visited.insert({box_next, person_next});
                            q.push({box_next, person_next});
                        }
                    }
                }
            }
            ++moves;
            // printf("\n");
        }
        return -1;
    }

    int minPushBox(CHAR_GRID &grid) {
        Pos start = find_in_grid(grid, 'S');
        Pos box = find_in_grid(grid, 'B');
        Pos target = find_in_grid(grid, 'T');

        return bfs(grid, box, start, target);
    }
};