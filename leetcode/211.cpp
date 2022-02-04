class TrieNode
{
public:
    unordered_map<char, TrieNode *> children;
    int count = 0;

    TrieNode() {}

    void add_end()
    {
        ++count;
    }

    bool has_end()
    {
        return count > 0;
    }

    TrieNode *get_child(char c)
    {
        if (!has_child(c))
        {
            children[c] = new TrieNode();
        }
        return children[c];
    }

    bool has_child(char c)
    {
        return children.find(c) != children.end();
    }
};

class Trie
{
public:
    TrieNode *root = nullptr;

    Trie() : root(new TrieNode()) {}

    void insert(const string &word)
    {
        insert(word, 0, root);
    }

    void insert(const string &word, int index, TrieNode *cur_node)
    {
        if (index >= word.size())
        {
            cur_node->add_end();
            return;
        }
        auto &cur_char = word[index];
        insert(word, index + 1, cur_node->get_child(cur_char));
        // insert(word, index+1, cur_node->get_child('.')); -> results in 2^l insert
    }

    bool search(const string &word)
    {
        return search(word, 0, root);
    }

    bool search(const string &word, int index, TrieNode *cur_node)
    {
        if (index >= word.size())
        {
            return cur_node->has_end();
        }

        auto c = word[index];
        if (c == '.')
        {
            for (auto &p : cur_node->children)
            {
                if (search(word, index + 1, p.second))
                {
                    return true;
                }
            }
        }
        else if (cur_node->has_child(c))
        {
            return search(word, index + 1, cur_node->get_child(c));
        }
        return false;
    }
};

class WordDictionary
{
public:
    Trie trie;
    WordDictionary()
    {
    }

    void addWord(string word)
    {
        trie.insert(word);
    }

    bool search(string word)
    {
        return trie.search(word);
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */