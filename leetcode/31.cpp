class Solution
{
public:
    void nextPermutation(vector<int> &nums)
    {
        int n = nums.size();
        int index = -1;
        for (int i = n - 1; i >= 1; --i)
        {
            if (nums[i - 1] < nums[i])
            {
                index = i - 1;
                break;
            }
        }

        if (index == -1)
        {
            reverse(nums.begin(), nums.end());
            return;
        }

        int index1 = -1;
        for (int i = index; i < n; ++i)
        {
            if (nums[i] > nums[index])
            {
                if (index1 == -1 || nums[i] <= nums[index1])
                {
                    index1 = i;
                }
            }
        }
        swap(nums[index], nums[index1]);
        reverse(nums.begin() + index + 1, nums.end());
    }
};