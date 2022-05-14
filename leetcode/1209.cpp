class Solution
{
public:
    string removeDuplicates(string s, int k)
    {
        vector<int> counts;
        vector<char> chars;
        for (auto c : s)
        {
            if (chars.size() == 0 || chars.back() != c)
            {
                chars.push_back(c);
                counts.push_back(1);
            }
            else
            {
                ++counts.back();
                if (counts.back() == k)
                {
                    counts.pop_back();
                    chars.pop_back();
                }
            }
        }
        string ret = "";
        for (int i = 0; i < chars.size(); ++i)
        {
            int count = counts[i];
            const auto &c = chars[i];
            while (count--)
            {
                ret += c;
            }
        }
        return ret;
    }
};