class Solution
{
public:
    unordered_map<int, bool> cache = {{0, false}};

    bool winnerSquareGame(int n)
    {
        if (cache.find(n) != cache.end())
            return cache[n];
        bool result = false;
        for (int i = 1; i * i <= n && !result; ++i)
        {
            if (!winnerSquareGame(n - i * i))
            {
                result = true;
            }
        }
        cache[n] = result;
        return result;
    }
};