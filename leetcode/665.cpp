class Solution
{
public:
    bool check(vector<int> &nums)
    {
        for (int i = 1; i < nums.size(); ++i)
            if (nums[i - 1] > nums[i])
                return false;
        return true;
    }

    bool checkPossibility(vector<int> &nums)
    {
        if (check(nums))
            return true;
        for (int i = 1; i < nums.size(); ++i)
        {
            if (nums[i - 1] > nums[i])
            {
                int a = nums[i - 1], b = nums[i];
                nums[i - 1] = nums[i] = a;
                if (check(nums))
                    return true;
                nums[i - 1] = nums[i] = b;
                if (check(nums))
                    return true;
                break;
            }
        }
        return false;
    }
};