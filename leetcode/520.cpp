class Solution
{
public:
    bool detectCapitalUse(string word)
    {
        int upper = 0;
        for (auto c : word)
        {
            if (isupper(c))
                ++upper;
        }
        if (upper == word.size() || upper == 0)
            return true;
        if (upper == 1 && isupper(word[0]))
            return true;
        return false;
    }
};