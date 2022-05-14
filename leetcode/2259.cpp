class Solution
{
public:
    string removeDigit(string number, char digit)
    {
        string ans = "";
        int n = number.size();
        for (int i = 0; i < n; ++i)
        {
            if (number[i] == digit)
            {
                string cur = number.substr(0, i) + number.substr(i + 1);
                if (ans == "" || ans < cur)
                {
                    ans = cur;
                }
            }
        }
        return ans;
    }
};