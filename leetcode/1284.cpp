typedef vector<vector<int>> MAT;

class MatHash {
public:
    size_t operator()(const MAT &mat) const {
        int ans = 0;
        for(auto &row : mat) {
            for(auto &num : row) {
                ans += num;
            }
        }
        return (size_t)ans;
    }
};

typedef unordered_set<MAT, MatHash> MAT_SET;

class Solution {
public:
    bool is_zero_mat(MAT &mat) {
        for(auto &row : mat) {
            for(auto &num : row) {
                if(num) return false;
            }
        }
        return true;
    }

    void print_mat(MAT &mat) {
        for(auto &row : mat) {
            for(auto &num : row) {
                printf("%d ", num);
            }
            puts("");
        }
        puts("");
        return ;
    }


    void flip_mat(MAT &mat, int i, int j) {
        // 4 neighbors
        mat[i][j] ^= 1;
        if(i-1 >= 0) mat[i-1][j] ^= 1;
        if(j-1 >= 0) mat[i][j-1] ^= 1;
        if(i+1 < mat.size()) mat[i+1][j] ^= 1;
        if(j+1 < mat[i].size()) mat[i][j+1] ^= 1;
    }

    int bfs(MAT &start) {
        if(is_zero_mat(start)) return 0;

        int M = start.size(), N = start[0].size();
        queue<MAT> q;
        MAT_SET visited;

        q.push(start);
        visited.insert(start);
        int moves = 0;
        while(q.size()) {
            int q_n = q.size();
            while(q_n--) {
                MAT cur = q.front();
                q.pop();
                if(is_zero_mat(cur)) return moves;
                for(int i = 0; i < M; ++i) {
                    for(int j = 0; j < N; ++j) {
                        flip_mat(cur, i, j);
                        if(visited.find(cur) == visited.end()) {
                            q.push(cur);
                            visited.insert(cur);
                        }
                        flip_mat(cur, i, j);
                    }
                }
            }
            ++moves;
        }
        return -1;
    }

    int minFlips(MAT &mat) {
        return bfs(mat);
    }
};
