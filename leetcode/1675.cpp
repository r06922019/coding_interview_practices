class Solution
{
public:
    bool is_odd(int x)
    {
        return x & 1;
    }

    bool is_even(int x)
    {
        return !is_odd(x);
    }

    int minimumDeviation(vector<int> &nums)
    {
        for (auto &num : nums)
        {
            if (is_odd(num))
            {
                num <<= 1;
            }
        }
        set<int> num_set(nums.begin(), nums.end());
        int ans = *num_set.rbegin() - *num_set.begin();
        while (true)
        {
            int max_num = *num_set.rbegin();
            if (is_odd(max_num))
                break;
            num_set.erase(max_num);
            num_set.insert(max_num >> 1);
            ans = min(ans, *num_set.rbegin() - *num_set.begin());
        }

        return ans;
    }
};