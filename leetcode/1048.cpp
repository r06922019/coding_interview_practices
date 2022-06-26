class Solution
{
public:
    vector<string> gen_prev(string word)
    {
        vector<string> ret;
        for (int i = 0; i < word.size(); ++i)
            ret.push_back(word.substr(0, i) + word.substr(i + 1));
        return ret;
    }

    int longestStrChain(vector<string> &words)
    {
        unordered_map<string, int> dp;
        sort(words.begin(), words.end(), [](const string &a, const string &b)
             { return a.size() < b.size() || (a.size() == b.size() && a < b); });
        int max_len = 0;
        for (auto word : words)
        {
            dp[word] = 1;
            for (auto prev : gen_prev(word))
                if (dp.find(prev) != dp.end())
                    dp[word] = max(dp[word], dp[prev] + 1);
            max_len = max(max_len, dp[word]);
        }
        return max_len;
    }
};