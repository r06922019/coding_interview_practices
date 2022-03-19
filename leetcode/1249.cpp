class Solution
{
public:
    string remove_b(string s, char a, char b)
    {
        int a_count = 0;
        string ret = "";
        for (auto c : s)
        {
            if (c == a)
            {
                ++a_count;
                ret += c;
            }
            else if (c == b)
            {
                if (a_count > 0)
                {
                    --a_count;
                    ret += c;
                }
            }
            else
            {
                ret += c;
            }
        }
        return ret;
    }

    string minRemoveToMakeValid(string s)
    {
        s = remove_b(s, '(', ')');
        reverse(s.begin(), s.end());
        s = remove_b(s, ')', '(');
        reverse(s.begin(), s.end());
        return s;
    }
};