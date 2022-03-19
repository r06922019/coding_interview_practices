class Solution
{
public:
    long long maximumSubsequenceCount(string text, string pattern)
    {
        char c1 = pattern[0], c2 = pattern[1];
        if (c1 == c2)
        {
            long long count = 0;
            for (auto c : text)
            {
                if (c == c1)
                    ++count;
            }
            ++count;
            return count * (count - 1) / 2;
        }

        vector<long long> counts(text.size(), 0);
        int c1_count = 0, n = text.size(), c2_count = 0;
        for (int i = 0; i < n; ++i)
        {
            if (text[i] == c1)
                ++c1_count;
            else if (text[i] == c2)
            {
                counts[i] = c1_count;
                ++c2_count;
            }
        }
        long long ans = accumulate(counts.begin(), counts.end(), (long long)0);
        return (c1_count > c2_count) ? ans + c1_count : ans + c2_count;
    }
};