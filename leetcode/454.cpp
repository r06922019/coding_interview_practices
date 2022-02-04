class Solution
{
public:
    int fourSumCount(vector<int> &nums1, vector<int> &nums2, vector<int> &nums3, vector<int> &nums4)
    {
        unordered_map<int, int> counter;
        for (auto num1 : nums1)
        {
            for (auto num2 : nums2)
            {
                ++counter[-num1 - num2];
            }
        }
        int ans = 0;
        for (auto num3 : nums3)
        {
            for (auto num4 : nums4)
            {
                ans += counter[num3 + num4];
            }
        }
        return ans;
    }
};