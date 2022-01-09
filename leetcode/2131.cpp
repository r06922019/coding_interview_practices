class Solution
{
public:
    int longestPalindrome(vector<string> &words)
    {
        unordered_map<string, int> counter;
        bool has_double = false;
        for (auto word : words)
        {
            ++counter[word];
        }

        int ans = 0;
        for (auto word : words)
        {
            string rev = word;
            reverse(rev.begin(), rev.end());
            if (word[0] == word[1])
            {
                if (counter[word] >= 2)
                {
                    ans += 4;
                    counter[word] -= 2;
                }
            }
            else if (counter[word] && counter[rev])
            {
                // printf("found %s\n", word.c_str());
                int tmp = min(counter[word], counter[rev]);
                ans += tmp * 4;
                counter[word] -= tmp;
                counter[rev] -= tmp;
            }
        }
        for (auto word : words)
        {
            if (word[0] == word[1] && counter[word] > 0)
                has_double = true;
        }
        return has_double ? ans + 2 : ans;
    }
};