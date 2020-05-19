#include <cstdio>
#include <vector>
#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <unordered_set>

using namespace std;

class Pos {
public:
    int i,j;
    Pos() {
        i = j = 0;
    }

    Pos(int _i, int _j) {
        i = _i;
        j = _j;
    }

    bool operator==(const Pos &other) const {
        return this->i == other.i && this->j == other.j;
    }
};

class MyHash {
public:
    size_t operator()(const Pos &p) const {
        int i = (p.i >= 0)? p.i : p.i ^ -1;
        int j = (p.j >= 0)? p.j : p.j ^ -1;
        return (i << 16) ^ j;
    }
};

typedef unordered_set<Pos, MyHash> POS_SET;

void assign_value(vector<vector<int>> &board, Pos p, int val) {
    board[p.i][p.j] = val;
}

bool can_put_on_board(vector<vector<int>> &board, POS_SET &polyomino) {
    for(auto &p : polyomino) {
        int i = p.i, j = p.j;
        if(i+1 < board.size() && board[i+1][j] != 1 && polyomino.find({i+1, j}) == polyomino.end()) {
            return false;
        }
    }
    return true;
}

void put_on_board(vector<vector<int>> &board, POS_SET &polyomino) {
    for(auto &p : polyomino) {
        assign_value(board, p, 1);
    }
}

string solve() {
    int rows, cols;
    scanf("%d%d", &rows, &cols);
    vector<string> board;
    for(int i = 0; i < rows; ++i) {
        string tmp;
        cin >> tmp;
        board.push_back(tmp);
    }

    unordered_map<char, POS_SET> polyominos;
    for(int i = 0; i < rows; ++i) {
        for(int j = 0; j < cols; ++j) {
            char &c = board[i][j];
            polyominos[c].insert({i,j});
        }
    }
    string ans = "";
    vector<vector<int>> cur_board(rows, vector<int>(cols, 0));
    while(polyominos.size()) {
        char cur_piece = 0;

        // pick one piece
        for(auto &it : polyominos) {
            if(can_put_on_board(cur_board, it.second)) {
                cur_piece = it.first;
                break;
            }
        }

        // check
        if(cur_piece < 'A') {
            ans = "-1";
            break;
        }
        else {
            // put on board
            put_on_board(cur_board, polyominos[cur_piece]);
            polyominos.erase(cur_piece);
            ans += cur_piece;
        }
    }
    return ans;
}


int main(void) {
    int t;
    scanf("%d", &t);
    for(int i = 1; i <= t; ++i) {
        cout << "Case #" << i << ": " << solve() << "\n";
    }
    return 0;
}