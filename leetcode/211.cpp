class TrieNode {
public:
    int count = 0;
    unordered_map<char, TrieNode*> children;
    TrieNode(){}
};

class Trie {
public:
    TrieNode *root = nullptr;
    Trie() {
        root = new TrieNode();
    }
    const bool EXPAND_AT_INSERT = false;
    const bool EXPAND_AT_SEARCH = true;
    void insert(string &word) {
        if(EXPAND_AT_INSERT) {
            insert(word, root, 0);
        }
        else {
            TrieNode *cur = root;
            for(auto &c : word) {
                if(cur->children.find(c) == cur->children.end()) {
                    cur->children[c] = new TrieNode();
                }
                cur = cur->children[c];
            }
            ++cur->count;
        }
    }

    void insert(string &word, TrieNode *cur, int index) {
        if(index == word.size()) {
            ++cur->count;
            return ;
        }
        for(auto &c : {'.', word[index]}) {
            if(cur->children.find(c) == cur->children.end()) {
                cur->children[c] = new TrieNode();
            }
            insert(word, cur->children[c], index+1);
        }
    }

    bool search(string &word) {
        if(EXPAND_AT_SEARCH) {
            return search(word, 0, root);
        }
        else {
            TrieNode *cur = root;
            for(auto &c : word) {
                if(cur->children.find(c) == cur->children.end()) {
                    return false;
                }
                cur = cur->children[c];
            }
            return cur->count > 0;
        }
        return false; // dummy
    }

    bool search(string &word, int index, TrieNode *cur) {
        if(index >= word.size()) {
            return cur->count > 0;
        }
        auto &c = word[index];
        if(c == '.') {
            for(auto &p : cur->children) {
                if(search(word, index+1, p.second))
                    return true;
            }
            return false;
        }
        else {
            if(cur->children.find(c) == cur->children.end()) {
                return false;
            }
            return search(word, index+1, cur->children[c]);
        }
        return false; // dummy
    }

};

class WordDictionary {
public:
    /** Initialize your data structure here. */
    Trie trie;
    WordDictionary() {

    }

    void addWord(string word) {
        trie.insert(word);
    }

    bool search(string word) {
        return trie.search(word);
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */