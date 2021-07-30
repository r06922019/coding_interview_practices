class Solution {
public:
    vector<vector<int>> dirs = {
        {0,1}, {0,-1}, {1,0}, {-1,0}
    };

    bool is_valid(vector<vector<char>>& board, int i, int j) {
        return i >= 0 && i < board.size() && j >= 0 && j < board[i].size();
    }

    bool dfs(vector<vector<char>>& board, int i, int j, string &word, int word_index) {
        if(word_index == word.size()) return true;

        char c = board[i][j];
        board[i][j] = '.';
        for(auto &dir : dirs) {
            int new_i = i + dir[0];
            int new_j = j + dir[1];
            if(is_valid(board, new_i, new_j) && board[new_i][new_j] == word[word_index]) {
                if(dfs(board, new_i, new_j, word, word_index+1))
                    return true;
            }
        }
        board[i][j] = c;
        return false;
    }


    bool exist(vector<vector<char>>& board, string word) {
        for(int i = 0; i < board.size(); ++i) {
            for(int j = 0; j < board[i].size(); ++j) {
                if(board[i][j] == word[0]) {
                    // init a search at board
                    if(dfs(board, i, j, word, 1))
                        return true;
                }
            }
        }
        return false;
    }
};