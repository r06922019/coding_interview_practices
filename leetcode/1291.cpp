class Solution
{
public:
    vector<int> sequentialDigits(int low, int high)
    {
        vector<int> ans;
        for (int len = 2; len <= 9; ++len)
        {
            for (int start = 1; start <= 9 - len + 1; ++start)
            {
                int num = 0;
                for (int i = 0, cur = start; i < len; ++i, ++cur)
                {
                    num = num * 10 + cur;
                }
                if (num >= low && num <= high)
                    ans.push_back(num);
            }
        }
        return ans;
    }
};