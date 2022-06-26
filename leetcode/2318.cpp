class Solution
{
public:
    int match(int x, int y)
    {
        if (x == 1 && y == 2)
            return true;
        if (x == 1 && y == 3)
            return true;
        if (x == 1 && y == 4)
            return true;
        if (x == 1 && y == 5)
            return true;
        if (x == 1 && y == 6)
            return true;
        if (x == 2 && y == 1)
            return true;
        if (x == 2 && y == 3)
            return true;
        if (x == 2 && y == 5)
            return true;
        if (x == 3 && y == 1)
            return true;
        if (x == 3 && y == 2)
            return true;
        if (x == 3 && y == 4)
            return true;
        if (x == 3 && y == 5)
            return true;
        if (x == 4 && y == 1)
            return true;
        if (x == 4 && y == 1)
            return true;
        if (x == 4 && y == 3)
            return true;
        if (x == 4 && y == 5)
            return true;
        if (x == 5 && y == 1)
            return true;
        if (x == 5 && y == 2)
            return true;
        if (x == 5 && y == 3)
            return true;
        if (x == 5 && y == 4)
            return true;
        if (x == 5 && y == 6)
            return true;
        if (x == 6 && y == 1)
            return true;
        if (x == 6 && y == 5)
            return true;
        return false;
    }

    const int MOD = 1e9 + 7, ARR_SIZE = 6 * 6 + 6 + 1;
    int mod(int x) { return x % MOD; }

    int add(int a, int b)
    {
        return mod(mod(a) + mod(b));
    }

    int distinctSequences(int n)
    {
        if (n == 1)
            return 6;
        vector<int> cur(ARR_SIZE, 0);
        const vector<int> one_to_six = {1, 2, 3, 4, 5, 6};
        for (const auto &i : one_to_six)
        {
            for (const auto &j : one_to_six)
            {
                if (match(i, j))
                {
                    cur[(6 * i + j)] = 1;
                }
            }
        }

        while (n > 2)
        {
            vector<int> new_cur(ARR_SIZE, 0);
            for (const auto &i : one_to_six)
            {
                for (const auto &j : one_to_six)
                {
                    if (match(i, j))
                    {
                        for (const auto &k : one_to_six)
                        {
                            if (i != k && match(j, k))
                            {
                                new_cur[(6 * j + k)] = add(new_cur[(6 * j + k)], cur[(6 * i + j)]);
                            }
                        }
                    }
                }
            }
            cur = new_cur;
            --n;
        }

        int ans = 0;
        for (auto x : cur)
        {
            ans = add(ans, x);
        }
        return ans;
    }
};