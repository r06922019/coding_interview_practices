class Solution
{
public:
    vector<int> split_to_digits(int n)
    {
        vector<int> digits(10, 0);
        while (n)
        {
            ++digits[n % 10];
            n = n / 10;
        }
        return digits;
    }

    bool reorderedPowerOf2(int n)
    {
        auto n_digits = split_to_digits(n);
        for (int x = 1; x <= 1e9; x <<= 1)
        {
            if (split_to_digits(x) == n_digits)
                return true;
        }
        return false;
    }
};