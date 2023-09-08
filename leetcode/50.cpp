class Solution
{
public:
    double myPow(double x, int n)
    {
        if (x == 0)
            return 0;
        if (n == 0)
            return 1;
        bool is_int_min = n == INT_MIN;
        if (is_int_min)
            n = INT_MIN + 1;
        bool neg = n < 0;
        n = abs(n);
        double ans = 1, mul = x;
        for (int i = 0; i < 31; ++i)
        {
            if ((1 << i) & n)
            {
                ans *= mul;
            }
            mul *= mul;
        }
        if (is_int_min)
            ans *= x;
        return (neg) ? 1 / ans : ans;
    }
};