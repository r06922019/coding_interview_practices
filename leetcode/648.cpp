class TrieNode {
public:
    int count = 0;
    unordered_map<char, TrieNode *> children;
    TrieNode(){}
};

class Trie {
public:
    TrieNode *root = nullptr;
    Trie () {
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

    int find_shortest_prefix_length(string &s) {
        TrieNode *cur = root;
        int cnt = 0;
        for(auto &c : s) {
            ++cnt;
            if(cur->children.find(c) == cur->children.end()) {
                return 0;
            }
            cur = cur->children[c];
            if(cur->count > 0) return cnt;
        }
        return 0;
    }
};

class Solution {
public:
    vector<string> split_by_spaces(string &s) {
        s += " ";
        vector<string> words;
        string buf = "";
        for(auto &c : s) {
            if(isspace(c)) {
                words.push_back(buf);
                buf = "";
            }
            else {
                buf += c;
            }
        }
        return words;
    }

    string replaceWords(vector<string>& dictionary, string sentence) {
        vector<string> words = split_by_spaces(sentence);
        Trie trie;
        for(auto &d : dictionary) trie.insert(d);
        for(auto &word : words) {
            int cnt = trie.find_shortest_prefix_length(word);
            if(cnt > 0) word = word.substr(0, cnt);
        }
        string ans = "";
        for(auto &word : words)
            ans += word + " ";
        ans.pop_back();
        return ans;
    }
};