class State {
public:
    int pos, speed;
    State() {
        pos = speed = 0;
    }

    State(int p, int s) {
        pos = p;
        speed = s;
    }

    vector<State> gen_next_states(int target) {
        vector<State> ret;

        int next_pos = pos + speed;
        int dis_from_next_pos_to_target = abs(next_pos - target);
        int dis_from_beginning = abs(target - 0);
        if(dis_from_next_pos_to_target < dis_from_beginning)  { // A
            if(abs(speed) < (INT_MAX >> 1))
                ret.push_back(State(pos+speed, 2*speed));
        }

        if(speed > 0)
            ret.push_back(State(pos, -1));
        else
            ret.push_back(State(pos, 1));

        return ret;
    }

    bool operator==(const State &other) const {
        return pos == other.pos && speed == other.speed;
    }

    bool operator!=(const State &other) const {
        return !(*this == other);
    }
};

class StateHash {
public:
    size_t operator()(const State &s) const {
        int pos = s.pos;
        if(pos < 0) pos ^= -1;

        int speed = s.speed;
        if(speed < 0) speed ^= -1;

        return pos ^ speed;
    }
};

typedef unordered_set<State, StateHash> STATE_SET;
typedef unordered_map<State, State, StateHash> STATE_MAP_STATE;

class Solution {
public:
    char get_action(State &prev, State &cur) {
        if(abs(prev.speed) == abs(cur.speed))
            return 'R';
        return 'A';
    }

    string print_seq(STATE_MAP_STATE &parent, State &state) {
        vector<char> ans;
        while(parent[state] != state) {
            ans.push_back(get_action(parent[state], state));
            state = parent[state];
        }
        return string(ans.rbegin(), ans.rend());
    }

    int racecar(int target) {
        State start(0, 1);
        queue<State> q;
        STATE_SET visited;
        STATE_MAP_STATE parent;

        q.push(start);
        visited.insert(start);
        parent[start] = start;

        int moves = 0;
        while(q.size()) {
            int q_n = q.size();
            while(q_n--) {
                State cur = q.front();
                q.pop();
                // printf("%d %d\n", cur.pos, cur.speed);
                if(cur.pos == target) {
                    // cout << print_seq(parent, cur) << endl;
                    return moves;
                }
                for(State &s : cur.gen_next_states(target)) {
                    if(visited.find(s) == visited.end()) {
                        visited.insert(s);
                        parent[s] = cur;
                        q.push(s);
                    }
                }
            }
            ++moves;
        }

        return 0;
    }
};
