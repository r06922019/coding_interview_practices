class Solution
{
public:
    long long countBadPairs(vector<int> &nums)
    {
        long long ans = 0;
        int n = nums.size();
        unordered_map<int, int> counter;
        for (int i = 0; i < n; ++i)
        {
            ++counter[nums[i] - i];
        }
        for (auto &p : counter)
        {
            int count = p.second;
            ans += (long long)count * (n - count);
        }
        return ans / 2;
    }
};