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

    bool operator==(const Pos &other) const {
        return this->i == other.i && this->j == other.j;
    }

    Pos add_vec(vector<int> &v) {
        Pos p = *this;
        p.i += v[0];
        p.j += v[1];
        return p;
    }

    bool is_valid(vector<vector<char>> &board, char val) {
        return this->i >= 0 && this->i < board.size()
            && this->j >= 0 && this->j < board[this->i].size()
            && board[this->i][this->j] == val;
    }

    vector<Pos> get_valid_neighbors(vector<vector<char>> &board) {
        static vector<vector<int>> dirs = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
        vector<Pos> ret;
        for(auto &dir : dirs) {
            Pos cur = this->add_vec(dir);
            if(cur.is_valid(board, 'O')) {
                ret.push_back(cur);
            }
        }
        return ret;
    }
};

class MyHash {
public:
    size_t operator()(const Pos &p) const {
        int i = (p.i >= 0)? p.i : p.i^-1;
        int j = (p.j >= 0)? p.j : p.j^-1;
        return (i << 16) ^ j;
    }
};

typedef unordered_set<Pos, MyHash> POS_SET;

class Solution {
public:

    void bfs(vector<vector<char>>& board, Pos start, POS_SET &visited) {
        queue<Pos> q;
        q.push(start);
        visited.insert(start);

        while(q.size()) {
            Pos cur = q.front();
            q.pop();
            for(Pos &n : cur.get_valid_neighbors(board)) {
                if(visited.find(n) == visited.end()) {
                    q.push(n);
                    visited.insert(n);
                }
            }
        }

        return ;
    }

    char get_value(vector<vector<char>> &board, Pos &p) {
        return board[p.i][p.j];
    }

    void assign_value(vector<vector<char>>& board, Pos &p, char value) {
        board[p.i][p.j] = value;
    }

    void solve(vector<vector<char>>& board) {
        if(board.empty() || board.front().empty()) return;
        int M = board.size(), N = board.front().size();
        POS_SET visited;

        Pos tmp(0,0);
        for(auto &i : {0, M-1}) {
            tmp.i = i;
            for(int j = 0; j < N; ++j) {
                tmp.j = j;
                if(get_value(board, tmp) == 'O') {
                    bfs(board, Pos(i, j), visited);
                }
            }
        }

        for(int i = 0; i < M; ++i) {
            tmp.i = i;
            for(auto &j : {0, N-1}) {
                tmp.j = j;
                if(get_value(board, tmp) == 'O') {
                    bfs(board, Pos(i, j), visited);
                }
            }
        }

        for(int i = 0; i < M; ++i) {
            tmp.i = i;
            for(int j = 0; j < N; ++j) {
                tmp.j = j;
                if(get_value(board, tmp) == 'O' && visited.find(tmp) == visited.end()) {
                    assign_value(board, tmp, 'X');
                }
            }
        }
    }
};