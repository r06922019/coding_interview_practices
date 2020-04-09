std::vector<std::string> wordBoggle(std::vector<std::vector<char>> board, std::vector<std::string> words) {
    vector<string> ans;
    sort(words.begin(), words.end());
    for(string &word : words) {
        bool found = false;
        for(int i = 0; i < board.size() && !found; ++i) {
            for(int j = 0; j < board[i].size() && !found; ++j) {
                if(board[i][j] == word[0]) {
                    found = found | search_for(0, word, board, i, j);
                }
            }
        }
        if(found) {
            ans.push_back(word);
        }
    }
    return ans;
}

bool search_for(int index, string &word, vector<vector<char>> &board, int i, int j) {
    if(index+1 == word.size()) {
        return true;
    }
    bool found = false;
    board[i][j] = 0;
    for(int new_i = i-1; new_i <= i+1 && !found; ++new_i) {
        for(int new_j = j-1; new_j <= j+1 && !found; ++new_j) {
            if(0 <= new_i && new_i < board.size()) {
                if(0 <= new_j && new_j < board[new_i].size()) {
                    if(board[new_i][new_j] == word[index+1]) {
                        found = found | search_for(index+1, word, board, new_i, new_j);
                    }
                }
            }
        }
    }

    board[i][j] = word[index];
    return found;
}

