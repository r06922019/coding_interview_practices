class MyHashMap
{
public:
    static constexpr int N_BUCKETS = 1024;
    static constexpr bool N_BUCKETS_IS_POWER_OF_2 = ((N_BUCKETS & (N_BUCKETS - 1)) == 0);
    vector<pair<int, int> > buckets[N_BUCKETS];

    MyHashMap()
    {
    }

    int get_bucket_index(int key)
    {
        if (N_BUCKETS_IS_POWER_OF_2)
        {
            return key & (N_BUCKETS - 1);
        }
        else
        {
            return key % N_BUCKETS;
        }
    }

    void put(int key, int value)
    {
        int b_index = get_bucket_index(key);
        auto &v = buckets[b_index];
        for (auto &p : v)
        {
            if (p.first == key)
            {
                p.second = value;
                return;
            }
        }
        v.push_back({key, value});
    }

    int get(int key)
    {
        int b_index = get_bucket_index(key);
        auto v = buckets[b_index];
        for (auto &p : v)
        {
            if (p.first == key)
            {
                return p.second;
            }
        }
        return -1;
    }

    void remove(int key)
    {
        int b_index = get_bucket_index(key);
        auto &v = buckets[b_index];
        for (int i = 0; i < v.size(); ++i)
        {
            if (v[i].first == key)
            {
                v.erase(v.begin() + i);
                return;
            }
        }
    }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */