class Item
{
public:
    int group = 0;
    char c = 'q';
    Item(char _c, int _group)
    {
        c = _c;
        group = _group;
    }

    bool operator<(const Item &other) const
    {
        return (this->group < other.group) || (this->group == other.group && this->c < other.c);
    }
};

class Solution
{
public:
    int get_group(vector<int> &groups, const int &x)
    {
        if (groups[x] != x)
        {
            int group = get_group(groups, groups[x]);
            groups[x] = group;
        }
        return groups[x];
    }

    void merge_group(vector<int> &groups, const int &a, const int &b)
    {
        int group_a = get_group(groups, a);
        int group_b = get_group(groups, b);
        groups[group_a] = group_b;
    }

    string smallestStringWithSwaps(string s, vector<vector<int> > &pairs)
    {
        int n = s.size();
        vector<int> groups(n, 0);
        for (int i = 0; i < n; ++i)
        {
            groups[i] = i;
        }

        for (const auto &p : pairs)
        {
            int a = p[0], b = p[1];
            merge_group(groups, a, b);
        }

        vector<Item> items;
        unordered_map<int, vector<int> > group_to_index;
        for (int i = 0; i < n; ++i)
        {
            get_group(groups, i);
            items.push_back(Item(s[i], groups[i]));
            group_to_index[groups[i]].push_back(i);
        }

        for (auto &p : group_to_index)
        {
            auto &v = p.second;
            reverse(v.begin(), v.end());
        }

        sort(items.begin(), items.end());
        for (const auto &item : items)
        {
            const auto &group = item.group;
            const auto &index = *group_to_index[group].rbegin();
            char c = item.c;
            s[index] = c;
            group_to_index[group].pop_back();
        }
        return s;
    }
};