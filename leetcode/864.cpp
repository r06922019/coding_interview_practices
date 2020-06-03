class Solution {
public:
    int shortestPathAllKeys(vector<string>& grid) {
        int total_keys = 0;
        int init_state = get_init_state(grid, total_keys); // 5 bit i 5 bit j 6 bit keys

        vector<vector<int>> dirs = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
        unordered_set<int> visited;
        queue<int> q;
        q.push(init_state);
        visited.insert(init_state);
        int steps = 0;
        while(q.size()) {
            for(int q_i = 0, q_n = q.size(); q_i < q_n; ++q_i) {
                int cur_state = q.front();
                q.pop();

                // unpack
                int i = get_i(cur_state), j = get_j(cur_state);
                // printf("%d cur %d %d\n", steps, i, j);

                // collect key
                if('a' <= grid[i][j] && grid[i][j] <= 'f') {
                    cur_state = add_key(cur_state, grid[i][j]);
                    // printf("Added key %c\n", grid[i][j]);
                }

                // ending condition
                if(count_key(cur_state) == total_keys) return steps;

                // span neighbor
                for(auto &v : dirs) {
                    int new_i = i + v[0];
                    int new_j = j + v[1];
                    // printf("trying %d %d\n", new_i, new_j);
                    if(new_i >= 0 && new_i < grid.size()) {
                        if(new_j >= 0 && new_j < grid[new_i].size()) {
                            char &next_pos = grid[new_i][new_j];
                            if(next_pos == '.' || next_pos == '@' ||
                               is_key(next_pos) ||
                               (is_lock(next_pos) && test_key(cur_state, next_pos))
                              ) {
                                cur_state = set_i(cur_state, new_i);
                                cur_state = set_j(cur_state, new_j);
                                if(visited.find(cur_state) == visited.end()) {
                                    // printf("added %d %d\n", new_i, new_j);
                                    visited.insert(cur_state);
                                    q.push(cur_state);
                                }
                            }
                        }
                    }
                }
            }
            ++steps;
        }
        return -1;
    }

    bool is_key(char &c) {
        return 'a' <= c && c <= 'f';
    }

    bool is_lock(char &c) {
        return 'A' <= c && c <= 'F';
    }

    int get_init_state(vector<string> &grid, int &key_count) {
        vector<int> pos;
        for(int i = 0; i < grid.size(); ++i) {
            for(int j = 0; j < grid[i].size(); ++j) {
                if(grid[i][j] == '@') {
                    pos.push_back(i);
                    pos.push_back(j);
                }
                else if('a' <= grid[i][j] && grid[i][j] <= 'f') {
                    ++key_count;
                }
            }
        }
        return (pos[0] << (5+6)) + (pos[1] << 6);
    }

    int get_i(int state) {
        return (state >> (5+6)) & ((1<<5) - 1);
    }

    int get_j(int state) {
        return (state >> (6)) & ((1<<5) - 1);
    }

    int set_i(int state, int i) {
        return (i << (5+6)) + (get_j(state) << 6) + (state & ((1<<6) - 1));
    }

    int set_j(int state, int j) {
        return (get_i(state) << (5+6)) + (j << 6) + (state & ((1<<6) - 1));
    }

    bool test_key(int state, char lock) {
        return state & (1 << (tolower(lock) - 'a'));
    }

    int add_key(int state, char key) {
        return state | (1 << (tolower(key) - 'a'));
    }

    int count_key(int state) {
        int count = 0;
        for(int i = 0; i < 6; ++i, state >>= 1) {
            if(state & 1)
                ++count;
        }
        return count;
    }
};