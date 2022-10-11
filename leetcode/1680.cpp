class Solution
{
public:
    const int MOD = 1e9 + 7;
    int mod(const int &x)
    {
        return x % MOD;
    }
    int mod(const long long &x)
    {
        return x % MOD;
    }
    int add(const int &a, const int &b)
    {
        return mod(mod(a) + mod(b));
    }
    int mul(const int &a, const int &b)
    {
        long long tmp = mod(a);
        tmp = tmp * mod(b);
        return mod(tmp);
    }
    int concatenatedBinary(int n)
    {
        long long ans = 0;
        for (int cur_digit = 1, i = 1; i <= n; ++i)
        {
            if ((1 << cur_digit) == i)
                ++cur_digit;
            ans = add(mod(ans << cur_digit), i);
            // ans = add(mul(ans, (1<<cur_digit)), i);
        }
        return ans;
    }
};