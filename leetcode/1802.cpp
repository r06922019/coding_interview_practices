class Solution
{
public:
    long long count(const long long min_val, const long long val, const int len)
    {
        const int l = min((long long)len, val - min_val + 1);
        const long long s = val - l + 1;
        return (s + val) * l / 2 + max(len - l, 0);
    }
    bool check(long long x, long long n, int index, long long maxSum)
    {
        const long long a = index, b = n - index - 1;
        const long long total = x + count(1, x - 1, a) + count(1, x - 1, b);
        return total > maxSum;
    }
    int maxValue(int n, int index, int maxSum)
    {
        int l = 1, r = maxSum + 1;
        while (l < r)
        {
            const int mid = l + (r - l) / 2;
            if (check(mid, n, index, maxSum))
            {
                r = mid;
            }
            else
                l = mid + 1;
        }
        return l - 1;
    }
};