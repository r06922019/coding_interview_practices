class Solution
{
public:
    int gen_result(const string &word)
    {
        int result = 0;
        for (auto c : word)
        {
            result |= 1 << (c - 'a');
        }
        return result;
    }
    int maxProduct(vector<string> &words)
    {
        vector<int> chars_used;
        for (auto word : words)
        {
            chars_used.push_back(gen_result(word));
        }

        int ans = 0, n = words.size();
        for (int i = 0; i < n; ++i)
            for (int j = i + 1; j < n; ++j)
                if (!(chars_used[i] & chars_used[j]))
                    ans = max(ans, (int)(words[i].size() * words[j].size()));
        return ans;
    }
};