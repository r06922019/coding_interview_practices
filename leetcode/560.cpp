class Solution
{
public:
    int subarraySum(vector<int> &nums, int k)
    {
        vector<int> acc_sums = {0};
        for (auto num : nums)
        {
            acc_sums.push_back(acc_sums.back() + num);
        }

        int ans = 0;
        unordered_map<int, int> seen;
        for (int s : acc_sums)
        {
            auto it = seen.find(s - k);
            if (it != seen.end())
            {
                ans += it->second;
            }
            ++seen[s];
        }
        return ans;
    }
};