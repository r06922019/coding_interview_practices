class Solution
{
public:
    vector<string> divideString(string s, int k, char fill)
    {
        vector<string> ans;
        int index = 0, n = s.size();
        while (index < n)
        {
            string token = "";
            for (int i = 0; i < k; ++i)
            {
                if (index < n)
                {
                    token += s[index];
                    ++index;
                }
                else
                    token += fill;
            }
            ans.push_back(token);
        }
        return ans;
    }
};