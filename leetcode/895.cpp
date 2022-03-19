class FreqStack
{
public:
    unordered_map<int, vector<int> > buckets;
    unordered_map<int, int> counts;
    int cur_max_count = 0;
    FreqStack()
    {
    }

    void push(int val)
    {
        ++counts[val];
        buckets[counts[val]].push_back(val);
        cur_max_count = max(cur_max_count, counts[val]);
    }

    int pop()
    {
        int ret = buckets[cur_max_count].back();
        buckets[cur_max_count].pop_back();
        --counts[ret];
        if (buckets[cur_max_count].size() == 0)
        {
            --cur_max_count;
        }
        return ret;
    }
};

/**
 * Your FreqStack object will be instantiated and called as such:
 * FreqStack* obj = new FreqStack();
 * obj->push(val);
 * int param_2 = obj->pop();
 */