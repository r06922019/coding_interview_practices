class TrieNode {
public:
    int count = 0; // count of words that ends here
    unordered_map<char, TrieNode *> children;
    TrieNode(){}
};

class Trie {
public:
    /** Initialize your data structure here. */
    TrieNode *root = nullptr;
    Trie() {
        root = new TrieNode();
    }

    /** Inserts a word into the trie. */
    void insert(string word) {
        TrieNode *cur = root;
        for(auto &c : word) {
            if(cur->children.find(c) == cur->children.end()) {
                cur->children[c] = new TrieNode();
            }
            cur = cur->children[c];
        }
        ++cur->count;
    }

    /** Returns if the word is in the trie. */
    bool search(string word) {
        TrieNode *cur = root;
        for(auto &c : word) {
            if(cur->children.find(c) == cur->children.end()) {
                return false;
            }
            cur = cur->children[c];
        }
        return cur->count > 0;
    }

    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        TrieNode *cur = root;
        for(auto &c : prefix) {
            if(cur->children.find(c) == cur->children.end()) {
                return false;
            }
            cur = cur->children[c];
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */