class Solution
{
public:
    int minOperations(vector<int> &nums, int x)
    {
        int n = nums.size(), total = accumulate(nums.begin(), nums.end(), 0);
        if (total <= x)
            return (total == x) ? n : -1;
        int l = 0, r = n - 1, cur = 0, ans = -1;
        while (cur < x && l < n)
        {
            cur += nums[l];
            ++l;
        }
        if (cur == x)
        {
            ans = l;
        }
        --l;
        // printf("l = %d, r = %d, cur = %d\n", l, r, cur);
        while (r > l)
        {
            cur += nums[r];
            while (cur > x && l >= 0)
            {
                cur -= nums[l];
                --l;
            }
            // printf("l = %d, r = %d, cur = %d\n", l, r, cur);
            if (cur == x)
            {
                int tmp = n - r + l + 1;
                if (ans == -1)
                    ans = tmp;
                else
                    ans = min(ans, tmp);
            }
            --r;
        }
        return ans;
    }
};