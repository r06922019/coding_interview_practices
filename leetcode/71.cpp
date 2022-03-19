class Solution
{
public:
    string simplifyPath(string path)
    {
        path += '/';
        vector<string> strs;
        string tmp = "";
        for (auto c : path)
        {
            tmp += c;
            if (c == '/')
            {
                if (tmp == "/")
                {
                    if (strs.size() == 0)
                        strs.push_back(tmp);
                }
                else if (tmp == "./")
                {
                    ;
                }
                else if (tmp == "../")
                {
                    if (strs.size() > 1)
                        strs.pop_back();
                }
                else
                {
                    strs.push_back(tmp);
                }
                tmp = "";
            }
        }

        if (strs.size() > 1)
        {
            strs.back().pop_back();
        }

        string ret = "";
        for (auto x : strs)
            ret += x;
        return ret;
    }
};
