class TrieNode {
public:
    int count = 0;
    int children_count = 0;
    string s = "";
    vector<TrieNode*> children = vector<TrieNode*>(26, nullptr);
    TrieNode(){}
};

class Trie {
public:
    TrieNode *root = nullptr;
    Trie() {
        root = new TrieNode();
    }

    void insert(string &word) {
        TrieNode *cur = root;
        for(auto &c : word) {
            ++cur->children_count;
            if(cur->children[c-'a'] == nullptr) {
                cur->children[c-'a'] = new TrieNode();
            }
            cur = cur->children[c-'a'];
        }
        ++cur->count;
        cur->s = word;
    }

    bool search(string &word) {
        TrieNode *cur = root;
        for(auto &c : word) {
            if(cur->children[c-'a'] == nullptr) {
                return false;
            }
            cur = cur->children[c-'a'];
        }
        return cur->count > 0;
    }

    void remove(string &word) {
        remove(root, word, 0);
    }

    void remove(TrieNode *cur, string &word, int index) {
        if(index == word.size()) {
            cur->s = "";
            --cur->count;
            return ;
        }
        auto &c = word[index];
        --cur->children_count;
        if(cur->children[c-'a'] == nullptr) {
            return ;
        }
        remove(cur->children[c-'a'], word, index+1);
        if(cur->children_count == 0) {
            for(auto &p : cur->children) {
                if(p) {
                    delete p;
                    p = nullptr;
                }
            }
        }
    }
};

class Solution {
public:

    vector<vector<int>> dirs = {
        {0,1},{0,-1},
        {1,0},{-1,0},
    };

    bool is_valid(vector<vector<char>>& board, int i, int j) {
        return i >= 0 && i < board.size() && j >= 0 && j < board[i].size();
    }

    void search_with_trie(vector<vector<char>>& board, int i, int j, vector<vector<bool>> &visited,
                          TrieNode *cur_node, vector<string> &ans) {

        if(cur_node->count > 0) {
            ans.push_back(cur_node->s);
            cur_node->count = 0;
        }

        for(auto &dir : dirs) {
            int new_i = i+dir[0];
            int new_j = j+dir[1];
            if(is_valid(board, new_i, new_j) && !visited[new_i][new_j]) {
                auto &c = board[new_i][new_j];
                if(cur_node->children[c-'a']) {
                    visited[new_i][new_j] = true;
                    search_with_trie(board, new_i, new_j, visited,
                                     cur_node->children[c-'a'], ans);
                    visited[new_i][new_j] = false;
                }
            }
        }
    }

    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        Trie trie;
        for(auto &word : words) {
            trie.insert(word);
        }

        vector<string> ans;
        vector<vector<bool>> visited(board.size(), vector<bool>(board[0].size(), false));
        TrieNode *root = trie.root;
        for(int i = 0; i < board.size(); ++i) {
            for(int j = 0; j < board[i].size(); ++j) {
                auto &c = board[i][j];
                if(root->children[c-'a']) {
                    visited[i][j] = true;
                    int ans_size = ans.size();
                    search_with_trie(board, i, j, visited, root->children[c-'a'], ans);
                    visited[i][j] = false;
                    for(int index = ans_size; index < ans.size(); ++index) {
                        trie.remove(ans[index]);
                    }
                }
            }
        }

        return ans;
    }
};