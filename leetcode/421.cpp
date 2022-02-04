class Node
{
public:
    int count = 0;
    vector<Node *> children = {nullptr, nullptr};

    Node() {}

    bool has_end()
    {
        return count > 0;
    }

    void set_end()
    {
        ++count;
    }

    Node *get_child(int key)
    {
        if (!has_child(key))
        {
            children[key] = new Node();
        }
        return children[key];
    }

    bool has_child(int key)
    {
        return children[key] != nullptr;
    }
};

class Tree
{
public:
    Node *root = nullptr;

    Tree()
    {
        root = new Node();
    }

    void insert(int num)
    {
        Node *cur = root;
        for (int i = 30; i >= 0; --i)
        {
            int key = ((1 << i) & num) >> i;
            cur = cur->get_child(key);
        }
        cur->set_end();
    }

    int find_xor_max(int num)
    {
        Node *cur = root;
        int ret = 0;
        for (int i = 30; i >= 0; --i)
        {
            int key = ((1 << i) & num) >> i;
            int target_key = key ^ 1;
            if (cur->has_child(target_key))
            {
                cur = cur->get_child(target_key);
                ret = ret | (1 << i);
            }
            else
            {
                cur = cur->get_child(key);
            }
        }
        return ret;
    }
};

class Solution
{
public:
    int findMaximumXOR(vector<int> &nums)
    {
        Tree tree;
        for (auto num : nums)
        {
            tree.insert(num);
        }

        int ans = 0;
        for (auto num : nums)
        {
            ans = max(ans, tree.find_xor_max(num));
        }
        return ans;
    }
};