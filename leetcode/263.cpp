class Solution
{
public:
    bool isUgly(int n)
    {
        if (n <= 0)
            return false;
        for (auto x : {2, 3, 5})
        {
            while (n % x == 0)
                n /= x;
        }
        return n == 1;
    }
};