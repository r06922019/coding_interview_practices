class Solution
{
public:
    int findPairs(vector<int> &nums, int k)
    {
        int ans = 0;
        unordered_map<int, int> seen;
        for (auto num : nums)
        {
            if (k != 0)
            {
                if (seen.find(num) == seen.end())
                {
                    for (auto target : {num + k, num - k})
                        if (seen.find(target) != seen.end())
                            ans += 1;
                }
            }
            else
            {
                if (seen.find(num) != seen.end() && seen[num] == 1)
                    ++ans;
            }
            ++seen[num];
        }
        return ans;
    }
};