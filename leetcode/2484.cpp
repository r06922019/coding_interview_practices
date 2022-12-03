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
        tmp *= mod(b);
        return mod(tmp);
    }
    void fill_in(vector<vector<int>> &prefix, string s, bool rrr)
    {
        vector<int> counts(10, 0);
        const int n = s.size();
        for (int i = 0; i < n - 1; ++i)
        {
            int digit = s[i] - '0';
            if (i >= 1)
            {
                prefix[i + 1] = prefix[i];
                for (int a = 0; a <= 9; ++a)
                {
                    const int num = (rrr) ? digit * 10 + a : a * 10 + digit;
                    prefix[i + 1][num] = add(prefix[i + 1][num], counts[a]);
                }
            }
            ++counts[digit];
        }
        if (rrr)
        {
            reverse(prefix.begin(), prefix.end());
        }
    }
    int countPalindromes(string s)
    {
        const int n = s.size();
        vector<vector<int>> prefix(n, vector<int>(100, 0)), suffix(n, vector<int>(100, 0));
        fill_in(prefix, s, false);
        fill_in(suffix, string(s.rbegin(), s.rend()), true);
        int ans = 0;
        for (int i = 2; i < n - 2; ++i)
        {
            for (int a = 0; a <= 9; ++a)
            {
                for (int b = 0; b <= 9; ++b)
                {
                    const int x = a * 10 + b, y = b * 10 + a;
                    ans = add(ans, mul(prefix[i][x], suffix[i][y]));
                }
            }
        }
        return ans;
    }
};