class Solution
{
public:
    int threeSumClosest(vector<int> &nums, int target)
    {
        sort(nums.begin(), nums.end());
        int ans = target + 3e4;
        for (int i = 0, n = nums.size(); i < n; ++i)
        {
            int l = i + 1, r = n - 1;
            const int t_ = target - nums[i];
            while (l < r)
            {
                const int x = nums[l] + nums[r];
                if (abs(t_ - x) < abs(target - ans))
                {
                    ans = nums[i] + x;
                }
                if (x > t_)
                {
                    --r;
                }
                else
                {
                    ++l;
                }
            }
        }
        return ans;
    }
};