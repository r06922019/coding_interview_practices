class Solution
{
public:
    long long zeroFilledSubarray(vector<int> &nums)
    {
        long long ans = 0, zeros = 0;
        for (auto x : nums)
        {
            if (x)
            {
                zeros = 0;
            }
            else
            {
                ans += zeros + 1;
                ++zeros;
            }
        }
        return ans;
    }
};