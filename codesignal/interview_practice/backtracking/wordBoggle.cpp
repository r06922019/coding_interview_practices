bool is_valid(int i, int j, vector<vector<char>> &board) {
    return (i >= 0 && i < board.size() && j >= 0 && j < board[i].size());
}

bool search_in_board(int i, int j, vector<vector<char>> &board,
    vector<vector<bool>> &visited, int index, string &word) {
    if(index == word.size()) return true;

    bool found = false;
    for(int di = -1; di <= 1 && !found; ++di) {
        for(int dj = -1; dj <= 1 && !found; ++dj) {
            if(is_valid(i+di, j+dj, board) && !visited[i+di][j+dj] && word[index] == board[i+di][j+dj]) {
                visited[i+di][j+dj] = true;
                if(search_in_board(i+di, j+dj, board, visited, index+1, word)) {
                    found = true;
                }
                visited[i+di][j+dj] = false;
            }
        }
    }
    return found;
}

vector<string> wordBoggle(vector<vector<char>> board, vector<string> words) {
    unordered_set<string> ans_set;
    int m = board.size(), n = board[0].size();
    vector<vector<bool>> visited(m, vector<bool>(n, false));
    for(auto &word : words) {
        if(word.empty()) {
            ans_set.insert("");
            continue;
        }
        bool found = false;
        for(int i = 0; i < m && !found; ++i) {
            for(int j = 0; j < n && !found; ++j) {
                if(word[0] == board[i][j]) {
                    visited[i][j] = true;
                    if(search_in_board(i, j, board, visited, 1, word)) {
                        found = true;
                    }
                    visited[i][j] = false;
                }
            }
        }
        if(found) {
            ans_set.insert(word);
        }
    }
    vector<string> ans(ans_set.begin(), ans_set.end());
    sort(ans.begin(), ans.end());
    return ans;
}
