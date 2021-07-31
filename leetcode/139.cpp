class Solution {
public:

    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> word_set(wordDict.begin(), wordDict.end());
        int n = s.size();
        vector<bool> results(n+1, false);
        results[0] = true;
        for(int i = 1; i <= n; ++i) {
            for(int j = 1; j <= i; ++j) {
                if(word_set.find(s.substr(i-j, j)) != word_set.end()) {
                    // printf("got a match for %s\n", s.substr(i-j, i).c_str());
                    results[i] = results[i] || results[i-j];
                }
            }
        }
        return results[n];
    }
};


// Trie
class TrieNode {
public:
    int count = 0;
    unordered_map<char, TrieNode *> children;
};

class Trie {
public:
    TrieNode *root = nullptr;
    Trie() {
        root = new TrieNode();
    }

    void insert(string &s) {
        TrieNode *cur = root;
        for(auto &c : s) {
            if(cur->children.find(c) == cur->children.end()) {
                cur->children[c] = new TrieNode();
            }
            cur = cur->children[c];
        }
        ++cur->count;
    }

    bool search(string &s, int start, int end) {
        TrieNode *cur = root;
        for(int i = start; i < end; ++i) {
            auto &c = s[i];
            if(cur->children.find(c) == cur->children.end()) {
                return false;
            }
            cur = cur->children[c];
        }
        return cur->count > 0;
    }
};

class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        int max_size_in_dict = 0;
        Trie trie;
        for(auto &s : wordDict) {
            max_size_in_dict = max(max_size_in_dict, (int)s.size());
            trie.insert(s);
        }
        int n = s.size();
        vector<bool> results(n+1, false);
        results[0] = true;
        for(int i = 0; i < n; ++i) {
            for(int j = 1; j <= max_size_in_dict; ++j) {
                if(i+j <= n) {
                    if(trie.search(s, i, i+j)) {
                        results[i+j] = results[i+j] || results[i];
                    }
                }
            }
        }
        return results[n];
    }
};