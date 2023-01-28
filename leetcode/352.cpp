class SummaryRanges
{
public:
    set<int> starts;
    vector<vector<int>> table;

    SummaryRanges() : table(1e4 + 1, vector<int>())
    {
    }

    bool seen(int x)
    {
        return table[x].size();
    }

    void addNum(int value)
    {
        // to avoid handling numbers inside the merged intervals
        if (seen(value))
            return;
        table[value] = {value, value};

        // x, y to represent the neighbors for neater code
        const int x = value - 1, y = value + 1;
        // a, b refer to the endpoints of the current interval
        int a = value, b = value;

        // if x is valid, the interval starts at the beginning of x's
        if (x >= 0 && seen(x))
            a = table[x][0];

        // if y is valid, the current interval ends at the end of y's
        // also, y is  no longer a valid start
        if (y < table.size() && seen(y))
        {
            b = table[y][1];
            starts.erase(y);
        }

        // update `a` to the starts, duplicated values are de-duped by set()
        starts.insert(a);
        // update the interval of a, b for further update
        table[a] = table[b] = {a, b};
    }

    vector<vector<int>> getIntervals()
    {
        vector<vector<int>> ans;
        for (auto x : starts)
        {
            ans.push_back(table[x]);
        }
        return ans;
    }
};

/**
 * Your SummaryRanges object will be instantiated and called as such:
 * SummaryRanges* obj = new SummaryRanges();
 * obj->addNum(value);
 * vector<vector<int>> param_2 = obj->getIntervals();
 */