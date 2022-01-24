class Solution
{
public:
    bool detectCapitalUse(string word)
    {
        bool type1 = true, type2 = true, type3 = false;

        for (auto c : word)
        {
            if (islower(c))
                type1 = false;
        }
        for (auto c : word)
        {
            if (isupper(c))
                type2 = false;
        }
        if (word.size() > 1 && isupper(word[0]))
        {
            type3 = true;
            for (int i = 1; i < word.size(); ++i)
                if (isupper(word[i]))
                    type3 = false;
        }
        return type1 || type2 || type3;
    }
};