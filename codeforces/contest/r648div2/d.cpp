#include <cstdio>
#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <string>
#include <cassert>
#include <stack>

using namespace std;

string YES = "Yes", NO = "No";
vector<vector<int>> dirs = {{0,1},{0,-1},{1,0},{-1,0}};

bool is_valid(int i, int j, int n, int m) {
    return i >= 0 && j >= 0 && i < n && j < m;
}

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
    Pos(vector<int> &vec) {
        assert(vec.size() == 2);
        i = vec[0];
        j = vec[1];
    }

    bool operator==(const Pos &other) const {
        return i == other.i && j == other.j;
    }

    bool operator!=(const Pos &other) const {
        return !(*this == other);
    }

    char get_value(vector<string> &grid) const {
        return grid[i][j];
    }

    void add_vec(vector<int> &vec) {
        assert(vec.size() == 2);
        i += vec[0];
        j += vec[1];
    }

    void minus_vec(vector<int> &vec) {
        assert(vec.size() == 2);
        i -= vec[0];
        j -= vec[1];
    }

    vector<Pos> get_4n(vector<string> &grid, int n, int m) {
        vector<Pos> ret;
        for(auto &dir : dirs) {
            this->add_vec(dir);
            if(is_valid(i, j, n, m) && this->get_value(grid) != '#') {
                ret.push_back(*this);
            }
            this->minus_vec(dir);
        }
        return ret;
    }
};

class PosHash {
public:
    static hash<int> hasher;
    size_t operator()(const Pos &p) const {
        return (hasher(p.i) << 4) ^ hasher(p.j);
    }
};
hash<int> PosHash::hasher = hash<int>();

typedef unordered_set<Pos, PosHash> POS_SET;

void dfs(vector<string> &grid, int start_i, int start_j, int n, int m, int &good_visited) {
    Pos start(start_i, start_j);
    stack<Pos> st;
    POS_SET visited;

    if(start.get_value(grid) != '#') {
        st.push(start);
        visited.insert(start);
    }

    while(st.size()) {
        Pos cur = st.top();
        st.pop();
        if(cur.get_value(grid) == 'G') ++good_visited;
        for(Pos &next : cur.get_4n(grid, n, m)) {
            if(visited.find(next) == visited.end()) {
                st.push(next);
                visited.insert(next);
            }
        }
    }

    return;
}

string solve() {
    int n, m;
    scanf("%d%d", &n, &m);
    vector<string> grid(n, "");
    for(int i = 0; i < n; ++i) {
        cin >> grid[i];
    }

    int bad_total = 0, good_total = 0;
    for(int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if(grid[i][j] == 'B') {
                ++bad_total;
            }
            else if(grid[i][j] == 'G') {
                ++good_total;
            }
        }
    }

    // no good -> block (n,m)
    if(good_total == 0) return YES;

    // block all B 4-neigh, if G is in 4-neigh, return No
    for(int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if(grid[i][j] == 'B') {
                for(auto &dir : dirs) {
                    int new_i = i + dir[0];
                    int new_j = j + dir[1];
                    if(is_valid(new_i, new_j, n, m)) {
                        char &c = grid[new_i][new_j];
                        if(c == 'G') return NO;
                        if(c != 'B') c = '#';
                    }
                }
            }
        }
    }

    // start search from (n,m) and see how many G are touched
    int good_visited = 0;
    dfs(grid, n-1, m-1, n, m, good_visited);
    return (good_visited == good_total)? YES:NO;
}

int main(int argc, char const *argv[]) {
    int t;
    scanf("%d", &t);
    while(t--) {
        cout << solve() << endl;
    }
    return 0;
}