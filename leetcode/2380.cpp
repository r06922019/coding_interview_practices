class Solution
{
public:
    int secondsToRemoveOccurrences(string s)
    {
        int cnt = 0;
        while (true)
        {
            bool changed = false;
            for (int i = 0; i < s.size(); ++i)
            {
                if (s[i] == '0' && s[i + 1] == '1')
                {
                    swap(s[i], s[i + 1]);
                    changed = true;
                    ++i;
                }
            }
            if (!changed)
                break;
            ++cnt;
        }
        return cnt;
    }
};