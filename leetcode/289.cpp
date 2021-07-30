class Solution {
public:
    bool is_valid(vector<vector<int>>& board, int i, int j) {
        return i >= 0 && i < board.size() && j >= 0 && j < board[i].size();
    }

#define prev_1_now_0 -3
#define prev_0_now_1 -4
#define prev_1_now_1 -5
#define prev_0_now_0 -6
    void gameOfLife(vector<vector<int>>& board) {
        int m = board.size(), n = board[0].size();
        for(int i = 0; i < m; ++i) {
            for(int j = 0; j < n; ++j) {
                int alive = 0;
                for(int di = -1; di <= 1; ++di) {
                    for(int dj = -1; dj <= 1; ++dj) {
                        if(di == 0 && dj == 0) continue;
                        if(is_valid(board, i+di, j+dj)) {
                            auto &x = board[i+di][j+dj];
                            if(x == 1 || x == prev_1_now_1 || x == prev_1_now_0) {
                                ++alive;
                            }
                        }
                    }
                }
                if(board[i][j] == 0) {
                    if(alive == 3)
                        board[i][j] = prev_0_now_1;
                    else
                        board[i][j] = prev_0_now_0;
                }
                else {
                    // 1,3
                    if(alive < 2 || alive > 3)
                        board[i][j] = prev_1_now_0;
                    else
                        board[i][j] = prev_1_now_1;
                }
            }
        }
        for(int i = 0; i < m; ++i) {
            for(int j = 0; j < n; ++j) {
                if(board[i][j] == prev_1_now_0 || board[i][j] == prev_0_now_0) {
                    board[i][j] = 0;
                }
                else {
                    board[i][j] = 1;
                }
            }
        }
    }
};