class Solution
{
public:
    int reverse(int x)
    {
        int ans = 0;
        while (x)
        {
            int digit = x % 10;
            if (digit > 0)
            { // x is positive
                if (ans > INT_MAX / 10)
                    return 0;
                ans *= 10;
                if (ans > INT_MAX - digit)
                    return 0;
                ans += digit;
            }
            else
            {
                if (ans < INT_MIN / 10)
                    return 0;
                ans *= 10;
                if (ans < INT_MIN - digit)
                    return 0;
                ans += digit;
            }
            x /= 10;
        }
        return ans;
    }
};