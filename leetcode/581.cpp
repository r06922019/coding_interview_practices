class Solution
{
public:
    int findUnsortedSubarray(vector<int> &nums)
    {
        int l = -1, r = -1, n = nums.size();
        {
            int cur_min = 1e6;
            for (int i = n - 1; i >= 0; --i)
            {
                if (nums[i] > cur_min)
                {
                    l = i;
                }
                else
                {
                    cur_min = nums[i];
                }
            }
        }
        {
            int cur_max = -1e6;
            for (int i = 0; i < n; ++i)
            {
                if (nums[i] < cur_max)
                {
                    r = i;
                }
                else
                {
                    cur_max = nums[i];
                }
            }
        }
        return (l != -1) ? r - l + 1 : 0;
    }
};