class Solution {
public:
    bool is_valid(vector<vector<char>>& board, int i, int j) {
        return i >= 0 && i < board.size() && j >= 0 && j < board[i].size();
    }

    void solve(vector<vector<char>>& board) {
        stack<vector<int>> st;
        int m = board.size(), n = board[0].size();
        for(int i = 0; i < m; ++i) {
            for(int j = 0; j < n; ++j) {
                if(i == 0 || j == 0 || i == m-1 || j == n-1) {
                    if(board[i][j] == 'O') {
                        st.push({i, j});
                        board[i][j] = '.';
                    }
                }
            }
        }
        vector<vector<int>> dirs = {
            {0,1}, {0, -1}, {1, 0}, {-1, 0}
        };
        while(st.size()) {
            auto cur = st.top();
            st.pop();
            for(auto &dir : dirs) {
                int new_i = cur[0] + dir[0];
                int new_j = cur[1] + dir[1];
                if(is_valid(board, new_i, new_j) && board[new_i][new_j] == 'O') {
                    board[new_i][new_j] = '.';
                    st.push({new_i, new_j});
                }
            }
        }

        for(int i = 0; i < m; ++i) {
            for(int j = 0; j < n; ++j) {
                if(board[i][j] == '.') {
                    board[i][j] = 'O';
                }
                else {
                    board[i][j] = 'X';
                }
            }
        }
    }
};