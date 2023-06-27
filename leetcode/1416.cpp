class Solution
{
public:
    const int MOD = 1e9 + 7;

    int mod(const int &x)
    {
        return x % MOD;
    }

    int add(const int &a, const int &b)
    {
        return mod(mod(a) + mod(b));
    }

    int numberOfArrays(string &s, int len, int k, vector<int> &dp)
    {
        if (dp[len] != -1)
            return dp[len];
        int ans = 0;
        long long cur = 0, mul = 1;
        for (int prev_len = len - 1; prev_len >= max(len - 10, 0); --prev_len)
        {
            // int cur = stoi(s.substr(prev_len, len-prev_len)); // stoi can't handle something like 3e9
            // long long cur = stoll(s.substr(prev_len, len-prev_len)); // stoll results in TLE
            cur = cur + mul * (s[prev_len] - '0');
            mul *= 10;
            if (s[prev_len] != '0' && cur <= k)
            {
                ans = add(ans, numberOfArrays(s, prev_len, k, dp));
            }
        }
        dp[len] = ans;
        return dp[len];
    }

    int numberOfArrays(string s, int k)
    {
        const int n = s.size();
        vector<int> dp(n + 1, -1);
        dp[0] = 1;
        return numberOfArrays(s, n, k, dp);
    }
};