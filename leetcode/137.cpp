class Solution
{
public:
    int singleNumber(vector<int> &nums)
    {
        int a = 0, b = 0;
        for (auto x : nums)
        {
            const int new_b = (b & ~(b & x)) | (a & x);
            x = x & ~(b & x);
            a = a ^ x;
            b = new_b;
        }
        return a;
    }
};