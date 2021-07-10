class Solution {
public:
    bool helper(vector<vector<char>> &board, vector<pair<int, int>> &to_fill, int index,
               vector<vector<bool>> &used_row, vector<vector<bool>> &used_col,
               vector<vector<vector<bool>>> &used9x9) {
        if(index == to_fill.size()) {
            return true;
        }

        printf("%d\n", index);
        pair<int, int> &p = to_fill[index];
        const int &r = p.first, &c = p.second;
        for(int num = 1; num <= 9; ++num) {
            if(!used_row[r][num] && !used_col[c][num] && !used9x9[r/3][c/3][num]) {
                used_row[r][num] = used_col[c][num] = used9x9[r/3][c/3][num] = true;
                board[r][c] = '0' + num;
                if(helper(board, to_fill, index+1, used_row, used_col, used9x9)) {
                    return true;
                }
                used_row[r][num] = used_col[c][num] = used9x9[r/3][c/3][num] = false;
                board[r][c] = '.';
            }
        }
        return false;
    }

    void solveSudoku(vector<vector<char>>& board) {
        vector<pair<int, int>> to_fill;
        vector<vector<bool>> used_row(9, vector<bool>(10, false)), used_col(9, vector<bool>(10, false));
        vector<vector<vector<bool>>> used9x9(3, vector<vector<bool>>(3, vector<bool>(10, false)));
        for(int i = 0; i < 9; ++i) {
            for(int j = 0; j < 9; ++j) {
                if(board[i][j] == '.') {
                    to_fill.push_back({i,j});
                }
                else {
                    int num = board[i][j] - '0';
                    used_row[i][num] = true;
                    used_col[j][num] = true;
                    used9x9[i/3][j/3][num] = true;
                }
            }
        }
        helper(board, to_fill, 0, used_row, used_col, used9x9);
    }
};