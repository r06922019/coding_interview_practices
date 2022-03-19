class Solution
{
public:
    vector<int> split_version(string version)
    {
        vector<int> ret;
        version += ".";
        string buf = "";
        for (auto c : version)
        {
            if (c == '.')
            {
                ret.push_back(stoi(buf));
                buf = "";
            }
            else
            {
                buf += c;
            }
        }
        return ret;
    }

    int compareVersion(string version1, string version2)
    {
        vector<int> v1 = split_version(version1);
        vector<int> v2 = split_version(version2);

        while (v1.size() < v2.size())
            v1.push_back(0);
        while (v1.size() > v2.size())
            v2.push_back(0);

        if (v1 < v2)
            return -1;
        else if (v1 > v2)
            return 1;
        return 0;
    }
};