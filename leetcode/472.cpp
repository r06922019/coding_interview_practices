class Solution
{
public:
    const int max_len = 30;
    unordered_map<string, int> cache;
    int check(const string &w, const unordered_set<string> &ss, int index)
    {
        if (index == w.size())
            return 0;

        const string w_ = w.substr(index);
        if (cache.find(w_) != cache.end())
            return cache[w_];

        for (int i = 0; i < max_len && index + i <= w.size(); ++i)
        {
            if (ss.find(w.substr(index, i)) != ss.end())
            {
                auto x = check(w, ss, index + i);
                if (x != -1)
                    return cache[w_] = x + 1;
            }
        }
        return cache[w_] = -1;
    }

    vector<string> findAllConcatenatedWordsInADict(vector<string> &words)
    {
        unordered_set<string> ss(words.begin(), words.end());
        vector<string> ret;
        for (auto w : words)
            if (check(w, ss, 0) >= 2)
                ret.push_back(w);
        return ret;
    }
};