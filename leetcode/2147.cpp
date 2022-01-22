class Solution
{
public:
    const int MOD = (int)(1e9 + 7);

    int mod(int x)
    {
        return x % MOD;
    }

    int mod(long long tmp)
    {
        tmp = tmp % MOD;
        return (int)tmp;
    }

    int mul(const int &a, const int &b)
    {
        long long tmp = mod(a);
        tmp *= mod(b);
        return mod(tmp);
    }

    int numberOfWays(string s)
    {
        unordered_map<char, int> counter;
        for (auto &c : s)
        {
            ++counter[c];
        }

        if (counter['S'] == 0 || counter['S'] % 2 == 1)
            return 0;

        vector<int> nums;
        int S = 0, P = 0;
        for (auto &c : s)
        {
            if (c == 'S')
            {
                if (S == 0)
                {
                    ++S;
                }
                else if (S > 0 && S % 2 == 0)
                {
                    nums.push_back(P);
                    ++S;
                }
                else
                {
                    // S > 0 && S % 2 == 1
                    P = 0;
                    ++S;
                }
            }
            else
            {
                ++P;
            }
        }
        int ans = 1;
        for (auto x : nums)
        {
            ans = mul(ans, mod(x + 1));
        }
        return ans;
    }
};