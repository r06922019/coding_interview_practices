class Solution
{
public:
    bool matchReplacement(string s, string sub, vector<vector<char> > &mappings)
    {
        unordered_map<char, unordered_set<char> > trans;
        for (auto mapping : mappings)
        {
            trans[mapping[0]].insert(mapping[1]);
        }

        for (int i = 0, n = sub.size(); i <= s.size() - n; ++i)
        {
            string cur = s.substr(i, n);
            bool matches = true;
            for (int j = 0; j < n && matches; ++j)
            {
                if (cur[j] != sub[j])
                {
                    if (trans[sub[j]].find(cur[j]) == trans[sub[j]].end())
                    {
                        matches = false;
                    }
                }
            }
            if (matches)
                return true;
        }
        return false;
    }
};