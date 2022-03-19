class Solution
{
public:
    string removeKdigits(string num, int k)
    {
        if (num.size() <= k)
            return "0";
        string ans = "";
        for (const auto &c : num)
        {
            while (k > 0 && ans.size() > 0 && ans.back() > c)
            {
                --k;
                ans.pop_back();
            }
            if (c != '0' || ans.size())
                ans.push_back(c);
        }

        while (ans.size() && k--)
            ans.pop_back();
        reverse(ans.begin(), ans.end());
        while (ans.size() && ans.back() == '0')
            ans.pop_back();
        reverse(ans.begin(), ans.end());
        return (ans.empty()) ? "0" : ans;
    }
};