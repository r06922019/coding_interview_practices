class Solution
{
public:
    int longestConsecutive(vector<int> &nums)
    {
        unordered_set<int> num_set(nums.begin(), nums.end());
        int ans = 0;
        for (auto num : num_set)
        {
            if (num_set.find(num - 1) == num_set.end())
            {
                int upper = num + 1, lower = num - 1;
                while (num_set.find(upper) != num_set.end())
                {
                    num_set.erase(upper);
                    ++upper;
                }
                ans = max(ans, upper - lower - 1);
            }
        }
        return ans;
    }
};