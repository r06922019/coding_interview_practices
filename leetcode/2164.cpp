class Solution
{
public:
    vector<int> sortEvenOdd(vector<int> &nums)
    {
        vector<int> even, odd, ans;
        int n = nums.size();
        for (int i = 0; i < n; ++i)
        {
            if (i % 2 == 0)
                even.push_back(nums[i]);
            else
                odd.push_back(nums[i]);
        }
        sort(even.rbegin(), even.rend());
        sort(odd.begin(), odd.end());
        for (int i = 0; i < n; ++i)
        {
            if (i % 2 == 0)
            {
                nums[i] = even.back();
                even.pop_back();
            }
            else
            {
                nums[i] = odd.back();
                odd.pop_back();
            }
        }

        return nums;
    }
};