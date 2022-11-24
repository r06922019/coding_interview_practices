class Solution
{
public:
    string removeDuplicates(string s)
    {
        vector<char> v;
        for (auto c : s)
        {
            if (v.size() && v.back() == c)
                v.pop_back();
            else
                v.push_back(c);
        }
        return string(v.begin(), v.end());
    }
};