class Solution
{
public:
    int xorAllNums(vector<int> &nums1, vector<int> &nums2)
    {
        int ans1 = 0, ans2 = 0;
        for (auto x : nums1)
            ans1 ^= x;
        for (auto x : nums2)
            ans2 ^= x;
        int ans = 0;
        if (nums1.size() % 2 == 1)
            ans ^= ans2;
        if (nums2.size() % 2 == 1)
            ans ^= ans1;
        return ans;
    }
};