class State {
public:
    string board, hand;
    State(string _b, string _h) {
        board = _b;
        hand = _h;
    }

    string gen_key() {
        return board + " " + hand;
    }

    bool ends() {
        return board.empty();
    }

    void reduce_board() {
        bool modified = true;
        string result = "";
        while(modified) {
            modified = false;
            int index = 0;
            while(index < board.size()) {
                int count = 0;
                char &cur = board[index];
                while(board[index] == cur) {
                    ++index;
                    ++count;
                }

                if(count >= 3) {
                    modified = true;
                }
                else {
                    while(count--) {
                        result += cur;
                    }
                }
            }
            board = result;
            result = "";
        }
        return ;
    }

    void add_ball(char ball, int index) {
        string new_board = (index > 0)? board.substr(0, index) : "";
        new_board += ball;
        new_board += (index < board.size())? board.substr(index) : "";
        board = new_board;
        reduce_board();
        return ;
    }

    vector<State> get_next_states() {
        vector<State> next_states;
        for(int i = 0; i < hand.size(); ++i) {
            if(i > 0 && hand[i] == hand[i-1]) continue;
            string new_hand = hand;
            new_hand.erase(i, 1);
            for(int j = 0; j <= board.size(); ++j) {
                State next_state(board, new_hand);
                next_state.add_ball(hand[i], j);
                next_states.push_back(next_state);
            }
        }
        return next_states;
    }
};

class Solution {
public:

    bool test_if_possible(string &board, string &hand) {
        unordered_map<char, int> board_count, hand_count;
        for(char &c : board) ++board_count[c];
        for(char &c : hand) ++hand_count[c];

        // definitely impossible
        for(auto &it : board_count) {
            char cur_char = it.first;
            int cur_count = it.second;
            if(hand_count.find(cur_char) != hand_count.end())
                cur_count += hand_count[cur_char];
            if(cur_count < 3) return false;
        }

        // shrink hand
        for(auto &it : hand_count) {
            char cur_char = it.first;
            if(board_count.find(cur_char) == board_count.end())
                it.second = 0; // remove useless ball;
        }

        // recover hand
        hand = "";
        for(auto &it : hand_count) {
            for(int i = 0; i < it.second; ++i)
                hand += it.first;
        }

        sort(hand.begin(), hand.end());
        return true;
    }

    int findMinStep(string board, string hand) {
        bool possible = test_if_possible(board, hand);
        if(!possible) return -1;

        int moves = 0;
        State init(board, hand);

        queue<State> q;
        q.push(init);

        unordered_set<string> visited;
        visited.insert(init.gen_key());

        while(q.size()) {
            for(int q_i = 0, q_n = q.size(); q_i < q_n; ++q_i) {
                State cur = q.front();
                q.pop();

                if(cur.ends()) return moves;

                vector<State> next_states = cur.get_next_states();
                for(State &n_s : next_states) {
                    string n_key = n_s.gen_key();
                    if(visited.find(n_key) == visited.end()) {
                        visited.insert(n_key);
                        q.push(n_s);
                    }
                }
            }
            ++moves;
        }
        return -1;
    }
};