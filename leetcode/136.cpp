class Solution
{
public:
    int singleNumber(vector<int> &nums)
    {
        int ans = 0;
        for (const auto &num : nums)
            ans ^= num;
        return ans;
    }
};