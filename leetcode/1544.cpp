class Solution
{
public:
    string makeGood(string s)
    {
        vector<char> ans;
        for (auto c : s)
        {
            if (ans.empty() || !(c != ans.back() && tolower(c) == tolower(ans.back())))
            {
                ans.push_back(c);
            }
            else
            {
                ans.pop_back();
            }
        }
        return string(ans.begin(), ans.end());
    }
};
