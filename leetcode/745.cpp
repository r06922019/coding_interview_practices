const auto DELIM = '#';
class TrieNode
{
public:
    int index = -1;
    unordered_map<char, TrieNode *> children;
    TrieNode() {}

    bool has_children(char key)
    {
        return children.find(key) != children.end();
    }

    TrieNode *get_children(char key)
    {
        if (!has_children(key))
            children[key] = new TrieNode();
        return children[key];
    }
};

class Trie
{
public:
    TrieNode *root = nullptr;
    Trie()
    {
        root = new TrieNode();
    }

    void insert(string key, int word_index, bool reverse)
    {
        string word;
        if (reverse)
            word = string(key.rbegin(), key.rend());
        else
            word = key;
        bool after_delim = false;
        TrieNode *cur = root;
        for (auto c : word)
        {
            cur = cur->get_children(c);
            if (c == DELIM)
                after_delim = true;
            else if (after_delim)
                cur->index = max(cur->index, word_index);
        }
    }

    int find(string key)
    {
        TrieNode *cur = root;
        for (auto c : key)
        {
            if (!cur->has_children(c))
            {
                return -1;
            }
            cur = cur->get_children(c);
        }
        return cur->index;
    }
};

class WordFilter
{
public:
    Trie trie;
    WordFilter(vector<string> &words)
    {
        for (int word_index = 0; word_index < words.size(); ++word_index)
        {
            const auto &word = words[word_index];
            string key = word + DELIM + word;
            for (int j = 0; j < word.size(); ++j)
            {
                trie.insert(key.substr(j), word_index, false);
            }
        }
    }

    int f(string prefix, string suffix)
    {
        string key = suffix + DELIM + prefix;
        return trie.find(key);
    }
};

/**
 * Your WordFilter object will be instantiated and called as such:
 * WordFilter* obj = new WordFilter(words);
 * int param_1 = obj->f(prefix,suffix);
 */