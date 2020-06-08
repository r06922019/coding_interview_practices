class State {
public:
    string board, hand;
    State () {
        board = hand = "";
    }

    State (string &b, string &h) {
        board = b;
        hand = h;
    }

    bool end() {
        return board.empty();
    }

    bool solvable() {
        // reduce_hand
        vector<int> hand_counter(26, 0);
        for(char &c : hand) {
            ++hand_counter[c-'A'];
        }

        vector<int> board_counter(26, 0);
        for(char &c : board) {
            ++board_counter[c-'A'];
        }

        for(int i = 0; i < 26; ++i) {
            if(board_counter[i] > 0) {
                if((board_counter[i] + hand_counter[i] < 3)) {
                    return false;
                }
            }
            else {
                hand_counter[i] = 0;
            }
        }

        hand = "";
        for(int i = 0; i < 26; ++i) {
            for(int j = 0; j < hand_counter[i]; ++j) {
                hand += ('A' + i);
            }
        }
        return true;
    }

    void reduce_board() {
        bool modified = true;
        while(modified) {
            modified = false;
            int index = 0, n = board.size();
            string new_board = "";
            while(index < n) {
                int count = 0;
                char &cur_ball = board[index];
                while(index < n && board[index] == cur_ball) {
                    ++index;
                    ++count;
                }
                if(count >= 3) {
                    modified = true;
                }
                else {
                    while(count--) {
                        new_board += cur_ball;
                    }
                }
            }
            board = new_board;
        }
    }

    vector<State> get_next_states() {
        vector<State> ret;
        for(int i = 0; i < hand.size(); ++i) {
            if(i == 0 || hand[i] != hand[i-1]) {
                for(int len = 0; len <= board.size(); ++len) {
                    string new_board = board.substr(0, len) + hand[i] + board.substr(len);
                    string new_hand = hand.substr(0, i) + hand.substr(i+1);
                    State new_state(new_board, new_hand);
                    new_state.reduce_board();
                    if(new_state.solvable()) {
                        ret.push_back(new_state);
                    }
                }
            }
        }
        return ret;
    }

    bool operator==(const State &other) const {
        return board == other.board && hand == other.hand;
    }

};

class StateHash {
public:
    static hash<string> hasher;
    size_t operator()(const State &s) const {
        return hasher(s.board) ^ hasher(s.hand);
    }
};
hash<string> StateHash::hasher = hash<string>();

typedef unordered_set<State, StateHash> STATE_SET;

class Solution {
public:
    int findMinStep(string board, string hand) {
        State start(board, hand);
        STATE_SET visited;
        queue<State> q;

        if(start.solvable()) {
            q.push(start);
            visited.insert(start);
        }

        int moves = 0;
        while(q.size()) {
            int q_n = q.size();
            while(q_n--) {
                State cur = q.front();
                q.pop();
                if(cur.end()) {
                    return moves;
                }
                for(auto &next_state : cur.get_next_states()) {
                    if(visited.find(next_state) == visited.end()) {
                        visited.insert(next_state);
                        q.push(next_state);
                    }
                }
            }
            ++moves;
        }
        return -1;
    }
};