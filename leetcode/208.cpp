class TrieNode
{
public:
    int count;
    bool ends;
    vector<TrieNode *> children;
    TrieNode() : count(0), children(26, nullptr), ends(false) {}

    TrieNode *gen_child(const char &c)
    {
        TrieNode *&child = children[c - 'a'];
        if (child == nullptr)
            child = new TrieNode();
        return child;
    }

    TrieNode *get_child(const char &c)
    {
        return gen_child(c);
    }

    void increment()
    {
        ++count;
    }
};

class Trie
{
public:
    TrieNode *root;
    Trie() : root(new TrieNode())
    {
    }

    void insert(string word)
    {
        TrieNode *cur = root;
        for (auto c : word)
        {
            cur->increment();
            cur = cur->get_child(c);
        }
        cur->increment();
        cur->ends = true;
    }

    bool search(string word)
    {
        TrieNode *cur = root;
        for (auto c : word)
        {
            cur = cur->get_child(c);
        }
        return cur->ends;
    }

    bool startsWith(string prefix)
    {
        TrieNode *cur = root;
        for (auto c : prefix)
        {
            cur = cur->get_child(c);
        }
        return cur->count > 0;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */