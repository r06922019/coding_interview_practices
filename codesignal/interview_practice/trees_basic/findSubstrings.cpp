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

    void insert(string &word) {
        TrieNode *cur = root;
        for(auto &c : word) {
            if(cur->children.find(c) == cur->children.end()) {
                cur->children[c] = new TrieNode();
            }
            cur = cur->children[c];
        }
        ++cur->count;
    }

    bool search(string &word) {
        TrieNode *cur = root;
        for(auto &c : word) {
            if(cur->children.find(c) == cur->children.end()) {
                return false;
            }
            cur = cur->children[c];
        }
        return cur->count > 0;
    }

    int search_until_first_unmatched(string &word, int start_index) {
        TrieNode *cur = root;
        int ret = -1;
        for(int i = start_index; i < word.size(); ++i) {
            auto &c = word[i];
            if(cur->count > 0)
                ret = max(ret, i);
            if(cur->children.find(c) == cur->children.end()) {
                return ret;
            }
            cur = cur->children[c];
        }
        if(cur->count > 0)
            ret = max(ret, (int)word.size());
        return ret;
    }
};

vector<string> findSubstrings(vector<string> words, vector<string> parts) {
    Trie trie;
    for(auto &part : parts) {
        trie.insert(part);
    }

    vector<string> ans;
    for(auto &word : words) {
        int max_len = 0, max_len_index = -1;
        for(int i = 0; i < word.size(); ++i) {
            int end = trie.search_until_first_unmatched(word, i);
            if(end - i > max_len) {
                max_len = end-i;
                max_len_index = i;
            }
        }
        if(max_len_index >= 0) {
            ans.push_back(word.substr(0, max_len_index) +
            "[" + word.substr(max_len_index, max_len) + "]" +
            word.substr(max_len_index + max_len));
        }
        else {
            ans.push_back(word);
        }
    }
    return ans;
}
