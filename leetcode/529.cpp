class Solution {
public:

    bool is_valid(vector<vector<char>>& board, int i, int j) {
        return (i >= 0 && i < board.size() && j >= 0 && j < board[i].size());
    }

    int is_adj_to_mine(vector<vector<char>>& board, int _i, int _j) {
        int count = 0;
        for(int i = _i-1; i <= _i+1; ++i) {
            for(int j = _j-1; j <= _j+1; ++j) {
                if(is_valid(board, i, j) && board[i][j] == 'M') {
                    ++count;
                }
            }
        }
        return count;
    }

    void visit(vector<vector<char>>& board, int i, int j) {
        int count = is_adj_to_mine(board, i, j);
        if(count) {
            board[i][j] = '0' + count;
        }
        else {
            board[i][j] = 'B';
        }
    }

    vector<vector<char>> updateBoard(vector<vector<char>>& board, vector<int>& click) {
        static vector<pair<int, int>> dirs = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
        int i = click[0], j = click[1];
        if(board[i][j] == 'M') {
            board[i][j] = 'X';
        }
        else if(board[i][j] == 'E') {
            queue<pair<int, int>> q;
            visit(board, i, j);
            if(board[i][j] == 'B')
                q.push({i,j});

            while(q.size()) {
                pair<int, int> cur_p = q.front();
                q.pop();

                i = cur_p.first;
                j = cur_p.second;

                // span 8 neigh == E
                for(int new_i = i-1; new_i <= i+1; ++new_i) {
                    for(int new_j = j-1; new_j <= j+1; ++new_j) {
                        if(is_valid(board, new_i, new_j) && board[new_i][new_j] == 'E') {
                            visit(board, new_i, new_j);
                            if(board[new_i][new_j] == 'B')
                                q.push({new_i, new_j});
                        }
                    }
                }
            }
        }
        return board;
    }
};