int M = 1e6, N = 1e6, MAX_AREA = 19900;

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
    Pos (vector<int> &v) {
        assert(v.size() == 2);
        i = v[0];
        j = v[1];
    }
    bool operator==(const Pos &other) const {
        return this->i == other.i && this->j == other.j;
    }

    Pos add_vec(vector<int> &v) {
        assert(v.size() == 2);
        Pos p = *this;
        p.i += v[0];
        p.j += v[1];
        return p;
    }

    bool is_valid() {
        return i >= 0 && i < M && j >= 0 && j < N;
    }

    vector<Pos> get_valid_neighbors() {
        static vector<vector<int>> dirs = {{1,0}, {0,1}, {0,-1}, {-1,0}};
        vector<Pos> ret;
        for(auto &dir : dirs) {
            Pos p = this->add_vec(dir);
            if(p.is_valid()) {
                ret.push_back(p);
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
        return i^j;
    }
};

typedef unordered_set<Pos, MyHash> POS_SET;

class Solution {
public:
    bool dfs(Pos &source, Pos &target, POS_SET &blocked_pos) {
        if(blocked_pos.find(source) != blocked_pos.end()) return false;
        if(blocked_pos.find(target) != blocked_pos.end()) return false;

        stack<Pos> st;
        POS_SET visited;
        st.push(source);
        visited.insert(source);

        while(st.size() && visited.size() <= MAX_AREA) {
            Pos cur = st.top();
            st.pop();
            if(cur == target) return true;
            for(Pos &n : cur.get_valid_neighbors()) {
                if(blocked_pos.find(n) == blocked_pos.end() && visited.find(n) == visited.end()) {
                    st.push(n);
                    visited.insert(n);
                }
            }
        }

        return visited.size() > MAX_AREA;
    }

    bool isEscapePossible(vector<vector<int>>& blocked, vector<int>& source, vector<int>& target) {
        POS_SET blocked_pos;
        for(auto &block : blocked) {
            blocked_pos.insert(Pos(block));
        }

        Pos source_pos(source), target_pos(target);
        return dfs(source_pos, target_pos, blocked_pos) && dfs(target_pos, source_pos, blocked_pos);
    }
};

