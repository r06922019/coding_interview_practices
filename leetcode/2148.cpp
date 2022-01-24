class Solution
{
public:
    int countElements(vector<int> &nums)
    {
        if (nums.size() <= 2)
            return 0;
        sort(nums.begin(), nums.end());
        int l = 0, r = nums.size() - 1;
        while (l < nums.size() && nums[l] == nums[0])
            ++l;
        while (r >= 0 && nums[r] == nums.back())
            --r;
        return (l <= r) ? r - l + 1 : 0;
    }
};