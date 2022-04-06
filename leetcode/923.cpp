class Solution
{
public:
    const int MOD = 1e9 + 7;

    int mod(int x)
    {
        return x % MOD;
    }

    int mod(long long x)
    {
        return x % MOD;
    }

    int add(int a, int b)
    {
        return mod(mod(a) + mod(b));
    }

    int mul(int a, int b)
    {
        long long tmp = mod(a);
        tmp *= mod(b);
        return mod(tmp);
    }

    int threeSumMulti(vector<int> &arr, int target)
    {
        int ans = 0;
        vector<int> counter(100 + 1, 0);
        for (int x : arr)
        {
            ++counter[x];
        }

        for (int j = 0; j <= 100; ++j)
        {
            if (counter[j] == 0)
                continue;

            //  1 j,  (i, j ,k)
            for (int i = 0; i < j; ++i)
            {
                const int k = target - i - j;
                if (i < j && j < k && k >= 0 && k < counter.size())
                {
                    ans = add(ans, mul(mul(counter[i], counter[j]), counter[k]));
                }
            }

            // 2 js
            if (target >= 2 * j)
            {
                const long long cur = counter[j] * (counter[j] - 1) / 2;
                const int x = target - 2 * j;
                if (x != j && x < counter.size())
                {
                    ans += mul(mod(cur), counter[x]);
                }
            }

            // 3j
            if (target == 3 * j)
            {
                const long long cur = (long long)counter[j] * (counter[j] - 1) * (counter[j] - 2);
                ans += mod(cur / 6);
            }
        }
        return ans;
    }
    /*
    int threeSumMulti(vector<int>& arr, int target) {
        int ans = 0, n = arr.size();
        for(int i = 0; i < n; ++i) {
            int cur = 0;
            vector<int> counter(100+1, 0);
            for(int j = i+1; j < n; ++j) {
                int k = target-arr[i]-arr[j];
                if(k >= 0 && k < counter.size()) {
                    cur = add(cur, counter[k]);
                }
                ++counter[arr[j]];
            }
            ans = add(ans, cur);
        }
        return ans;
    }
    */
};