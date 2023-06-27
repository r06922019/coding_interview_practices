class Solution
{
public:
    string removeStars(string s)
    {
        string ans = "";
        for (auto c : s)
        {
            if (c == '*')
            {
                ans.pop_back();
            }
            else
            {
                ans += c;
            }
        }
        return ans;
    }
};