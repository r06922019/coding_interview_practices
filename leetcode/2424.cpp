class LUPrefix
{
public:
    unordered_set<int> s;
    int cur_prefix = 0;
    LUPrefix(int n)
    {
    }

    void upload(int video)
    {
        s.insert(video);
        while (s.find(cur_prefix + 1) != s.end())
        {
            ++cur_prefix;
        }
    }

    int longest()
    {
        return cur_prefix;
    }
};

/**
 * Your LUPrefix object will be instantiated and called as such:
 * LUPrefix* obj = new LUPrefix(n);
 * obj->upload(video);
 * int param_2 = obj->longest();
 */