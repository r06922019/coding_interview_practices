class Solution
{
public:
    int minimumRecolors(string blocks, int k)
    {
        vector<int> acc_sum = {0};
        for (auto c : blocks)
        {
            acc_sum.push_back(acc_sum.back());
            if (c == 'W')
            {
                ++acc_sum.back();
            }
        }
        int ans = k;
        for (int i = k; i < acc_sum.size(); ++i)
        {
            ans = min(ans, (acc_sum[i] - acc_sum[i - k]));
        }
        return ans;
    }
};