class Solution
{
public:
    int removeDuplicates(vector<int> &nums)
    {
        int l = 0, r = 0, n = nums.size();
        while (r < n)
        {
            if (l >= 2 && nums[l - 2] == nums[l - 1])
            {
                while (r < n && nums[r] == nums[l - 1])
                    ++r;
                if (r < n)
                {
                    nums[l] = nums[r];
                    ++l, ++r;
                }
            }
            else
            {
                nums[l] = nums[r];
                ++l, ++r;
            }
        }
        return l;
    }
};