class Solution
{
public:
    const int MOD = 1e9 + 7;
    int countGoodStrings(int low, int high, int zero, int one)
    {
        vector<int> lens(high + 1, 0);
        int ans = 0;
        lens[0] = 1;
        for (int i = 1; i <= high; ++i)
        {
            if (i >= zero)
            {
                lens[i] = (lens[i - zero] + lens[i]) % MOD;
            }
            if (i >= one)
            {
                lens[i] = (lens[i - one] + lens[i]) % MOD;
            }
            if (i >= low)
                ans = (ans + lens[i]) % MOD;
        }
        return ans;
    }
};