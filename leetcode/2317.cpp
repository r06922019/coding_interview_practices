class Solution
{
public:
    int maximumXOR(vector<int> &nums)
    {
        int ans = 0;
        for (auto num : nums)
        {
            ans |= num;
        }
        return ans;
    }
};