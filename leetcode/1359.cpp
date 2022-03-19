class Solution
{
public:
    const int MOD = 1e9 + 7;

    int mod(int x) { return x % MOD; }
    int mod(long long x) { return x % MOD; }

    int mul(int a, int b)
    {
        long long tmp = mod(a);
        tmp *= mod(b);
        return mod(tmp);
    }

    int countOrders(int n)
    {
        int ans = 1;
        for (int i = 2 * n; i >= 2; i -= 2)
            ans = mul(ans, i * (i - 1) / 2);
        return ans;
    }
};