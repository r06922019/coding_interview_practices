class Solution
{
public:
    int findMaxLength(vector<int> &nums)
    {
        int ans = 0, c0 = 0, c1 = 0;
        unordered_map<int, int> diffs;
        diffs[0] = 0;
        for (int i = 0; i < nums.size(); ++i)
        {
            c0 += nums[i] ^ 1;
            c1 += nums[i];

            const int d = c0 - c1;
            auto it = diffs.find(d);
            if (it != diffs.end())
            {
                ans = max(ans, i + 1 - it->second);
            }
            else
            {
                diffs[d] = i + 1;
            }
        }

        return ans;
    }
};