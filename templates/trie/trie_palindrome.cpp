class TrieNode {
public:
    int index = -1;
    vector<int> indexs; // rest of the string is a palin
    unordered_map<char, TrieNode*> children;
    TrieNode(){}
};

class Trie {
public:
    TrieNode *root = nullptr;
    Trie() {
        root = new TrieNode();
    }

    static bool is_palin(string &word, int l, int r) {
        while(l < r) {
            if(word[l] != word[r]) return false;
            ++l,--r;
        }
        return true;
    }

    void insert(string &word, int &index) {
        TrieNode *cur = root;
        int n = word.size();
        for(int i = 0; i < n; ++i) {
            auto &c = word[i];
            if(is_palin(word, i, n-1)) {
                cur->indexs.push_back(index);
            }
            if(cur->children.find(c) == cur->children.end()) {
                cur->children[c] = new TrieNode();
            }
            cur = cur->children[c];
        }
        cur->index = index;
        cur->indexs.push_back(index);
    }

    void search_and_add(string &word, int &word_index, vector<vector<int>> &ans) {
        TrieNode *cur = root;
        int char_index, n = word.size();
        for(char_index = 0; char_index < n; ++char_index) {
            // some of a is matched, rest of a form a palindrom
            // b ends here
            if(is_palin(word, char_index, n-1) && cur->index >= 0) {
                if(word_index != cur->index)
                    ans.push_back({word_index, cur->index});
            }
            auto &c = word[char_index];
            if(cur->children.find(c) == cur->children.end()) {
                return;
            }
            cur = cur->children[c];
        }
        // a got all matched, so we add b if rest of b forms a palindrome
        for(auto &i : cur->indexs) {
            if(word_index != i)
                ans.push_back({word_index, i});
        }
    }
};

class Solution {
public:

    vector<vector<int>> palindromePairs(vector<string>& words) {
        Trie trie;
        int n = words.size();
        for(int i = 0; i < n; ++i) {
            string w(words[i].rbegin(), words[i].rend());
            trie.insert(w, i);
        }

        vector<vector<int>> ans;
        for(int i = 0; i < n; ++i) {
            trie.search_and_add(words[i], i, ans);
        }
        return ans;
    }
};