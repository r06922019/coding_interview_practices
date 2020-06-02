class Board {
public:
    vector<vector<int>> content;
    int zero_i = 0, zero_j = 0;

    Board () {}

    Board (vector<vector<int>> _content) {
        content = _content;
        // find zero
        bool not_found = true;
        for(int i = 0; i < content.size() && not_found; ++i) {
            for(int j = 0; j < content[i].size() && not_found; ++j) {
                if(content[i][j] == 0) {
                    zero_i = i;
                    zero_j = j;
                    not_found = false;
                }
            }
        }
    }

    Board (vector<vector<int>> _content, int z_i, int z_j) {
        content = _content;
        zero_i = z_i;
        zero_j = z_j;
    }

    int gen_key() const {
        int ret = 0;
        for(auto &row : content) {
            for(auto &val : row) {
                ret = (ret << 4) ^ val;
            }
        }
        return ret;
    }

    bool operator==(const Board &other) const {
        return content == other.content;
    }

    bool is_valid(int i, int j) const {
        return i >= 0 && i < content.size() && j >= 0 && j < content[i].size();
    }

    // span children
    vector<Board> get_next_states() const {
        static vector<vector<int>> dirs = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
        // switch 0 with 4-adjacent pos
        vector<Board> ret;
        for(auto &dir : dirs) {
            int new_i = zero_i + dir[0];
            int new_j = zero_j + dir[1];
            if(is_valid(new_i, new_j)) {
                Board new_board(content, new_i, new_j);
                swap(new_board.content[zero_i][zero_j], new_board.content[new_i][new_j]);
                ret.push_back(new_board);
            }
        }
        return ret;
    }
};


class BoardHash {
public:
    size_t operator()(const Board &b) const {
        return b.gen_key();
    }
};

typedef unordered_set<Board, BoardHash> BOARD_SET;

class Solution {
public:
    int slidingPuzzle(vector<vector<int>>& board) {
        Board start_state(board), end_state({{1,2,3}, {4,5,0}});
        queue<Board> q;
        BOARD_SET visited;

        int moves = 0;
        visited.insert(start_state);
        q.push(start_state);

        while(q.size()) {
            int q_n = q.size();
            while(q_n--) {
                Board cur = q.front();
                q.pop();
                if(cur == end_state) return moves;
                for(Board &next_board : cur.get_next_states()) {
                    if(visited.find(next_board) == visited.end()) {
                        visited.insert(next_board);
                        q.push(next_board);
                    }
                }
            }
            ++moves;
        }
        return -1;
    }
};