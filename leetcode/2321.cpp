class Solution
{
public:
    int helper(vector<int> &nums1, vector<int> &nums2)
    {
        int sum1 = accumulate(nums1.begin(), nums1.end(), 0);
        int sum2 = accumulate(nums2.begin(), nums2.end(), 0);
        int n = nums1.size();
        vector<int> diffs;
        for (int i = 0; i < n; ++i)
        {
            diffs.push_back(nums2[i] - nums1[i]);
        }
        int cur = 0, ans = 0;
        for (int i = 0; i < n; ++i)
        {
            cur = max(0, cur + diffs[i]);
            ans = max(ans, cur);
        }
        return sum1 + ans;
    }

    int maximumsSplicedArray(vector<int> &nums1, vector<int> &nums2)
    {
        return max(helper(nums1, nums2), helper(nums2, nums1));
    }
};