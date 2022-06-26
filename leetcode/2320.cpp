class Solution
{
public:
    const int MOD = 1e9 + 7;
    int mod(int x)
    {
        return x % MOD;
    }
    int add(int a, int b)
    {
        return mod(mod(a) + mod(b));
    }
    bool can_do(int i, int j)
    {
        if (i == 0)
            return true;
        if (i == 1)
            return j == 0 || j == 2;
        if (i == 2)
            return j == 0 || j == 1;
        if (i == 3)
            return j == 0;
        return false;
    }
    int countHousePlacements(int n)
    {
        vector<int> state{1, 0, 0, 0};
        while (n--)
        {
            vector<int> new_state{0, 0, 0, 0};
            for (int i = 0; i < 4; ++i)
            {
                for (int j = 0; j < 4; ++j)
                {
                    if (can_do(i, j))
                        new_state[j] = add(new_state[j], state[i]);
                }
            }
            state = new_state;
        }
        int ans = 0;
        for (auto x : state)
        {
            ans = add(ans, x);
        }
        return ans;
    }
};