class Solution
{
public:
    int missingNumber(vector<int> &nums)
    {
        int n = nums.size();
        const int SHIFT = n + 1;
        for (int i = 0; i < n; ++i)
        {
            auto num = nums[i];
            if (num >= SHIFT)
                num -= SHIFT;
            if (num < n)
            {
                nums[num] += SHIFT;
            }
        }
        int index = 0;
        while (index < n && nums[index] >= SHIFT)
            ++index;
        return index;
    }
};