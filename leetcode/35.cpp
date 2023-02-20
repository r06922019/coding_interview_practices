class Solution
{
public:
    int searchInsert(vector<int> &nums, int target)
    {
        if (target < nums[0])
            return 0;
        const int n = nums.size();
        if (target > nums.back())
            return n;
        int l = 0, r = n - 1;
        while (l < r)
        {
            const int mid = l + (r - l) / 2;
            if (nums[mid] < target)
            {
                l = mid + 1;
            }
            else
            {
                r = mid;
            }
        }
        return l;
    }
};