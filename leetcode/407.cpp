class Pos {
public:
    int i, j, val;
    Pos() {
        i = j = val = -1;
    }

    Pos(int _i, int _j, int _v) {
        i = _i;
        j = _j;
        val = _v;
    }

    bool operator==(const Pos &other) const {
        return i == other.i && j == other.j;
    }

    bool operator!=(const Pos &other) const {
        return !(*this == other);
    }

    void add_vec(vector<int> &v) {
        assert(v.size() == 2);
        i += v[0];
        j += v[1];
    }

    void minus_vec(vector<int> &v) {
        assert(v.size() == 2);
        i -= v[0];
        j -= v[1];
    }

    bool is_valid(vector<vector<int>>& heightMap) {
        return i >= 0 && i < heightMap.size() && j >= 0 && j < heightMap[i].size();
    }

    vector<Pos> get_neighbors(vector<vector<int>>& heightMap) {
        static vector<vector<int>> dir4 = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
        vector<Pos> ret;
        for(auto &dir : dir4) {
            this->add_vec(dir);
            if(this->is_valid(heightMap)) {
                ret.emplace_back(i, j, heightMap[i][j]);
            }
            this->minus_vec(dir);
        }
        return ret;
    }
};

class PosHash {
public:
    size_t operator()(const Pos &p) const {
        return (p.i << 8) ^ p.j;
    }
};

class Solution {
public:
    int trapRainWater(vector<vector<int>>& heightMap) {
        if(heightMap.empty() || heightMap[0].empty()) return 0;

        int m = heightMap.size(), n = heightMap[0].size();
        if(m == 1 || n == 1) return 0;

        auto comp = []( Pos &a, Pos &b ) { return a.val > b.val; }; // min_queue
        priority_queue<Pos, vector<Pos>, decltype(comp)> pq(comp);
        unordered_set<Pos, PosHash> visited;

        // hash<int> int_hasher;
        // function<size_t (const Pos)> pos_hash_func = [&int_hasher](const Pos &p) {
        //     return (int_hasher(p.i) << 4) ^ int_hasher(p.j);
        // };
        // function<bool (const Pos, const Pos)> pos_equal_func = [](const Pos &a, const Pos &b) {
        //     return a == b;
        // };
        // unordered_set<Pos, decltype(pos_hash_func), decltype(pos_equal_func)> visited(256, pos_hash_func, pos_equal_func);

        for(int i = 0; i < m; ++i) {
            for(int j = 0; j < n; ++j) {
                if(i == 0 || j == 0 || i == m-1 || j == n-1) {
                    Pos p(i, j, heightMap[i][j]);
                    visited.insert(p);
                    pq.push(p);
                }
            }
        }

        int ans = 0, cur_wall_height = 0;
        while(pq.size()) {
            Pos cur = pq.top();
            pq.pop();
            cur_wall_height = max(cur_wall_height, cur.val);
            ans += (cur_wall_height - cur.val);
            for(auto &p : cur.get_neighbors(heightMap)) {
                if(visited.find(p) == visited.end()) {
                    visited.insert(p);
                    pq.push(p);
                }
            }
        }

        return ans;
    }
};