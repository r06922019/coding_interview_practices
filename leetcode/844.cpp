class Solution
{
public:
    string eval(const string s)
    {
        string ret = "";
        for (auto &c : s)
        {
            if (c == '#')
            {
                if (ret.size())
                    ret.pop_back();
            }
            else
                ret += c;
        }
        return ret;
    }

    bool backspaceCompare(string s, string t)
    {
        return eval(s) == eval(t);
    }
};