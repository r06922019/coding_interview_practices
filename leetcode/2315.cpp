class Solution
{
public:
    int countAsterisks(string s)
    {
        int asterisks = 0, bar = 0;
        for (auto c : s)
        {
            if (c == '*')
            {
                if (bar % 2 == 0)
                {
                    ++asterisks;
                }
            }
            else if (c == '|')
            {
                ++bar;
            }
        }
        return asterisks;
    }
};