class Solution
{
public:
    char get_group(unordered_map<char, char> &groups, char x)
    {
        if (groups[x] != x)
        {
            groups[x] = get_group(groups, groups[x]);
        }
        return groups[x];
    }

    void merge_groups(unordered_map<char, char> &groups, char a, char b)
    {
        auto g_a = get_group(groups, a);
        auto g_b = get_group(groups, b);
        groups[g_b] = g_a;
    }

    bool equationsPossible(vector<string> &equations)
    {
        unordered_map<char, char> groups;
        for (auto eq : equations)
        {
            groups[eq[0]] = eq[0];
            groups[eq[3]] = eq[3];
        }
        for (auto eq : equations)
        {
            if (eq[1] == '=')
            {
                merge_groups(groups, eq[0], eq[3]);
            }
        }
        for (auto eq : equations)
        {
            if (eq[1] == '!')
            {
                if (get_group(groups, eq[0]) == get_group(groups, eq[3]))
                    return false;
            }
        }
        return true;
    }
};