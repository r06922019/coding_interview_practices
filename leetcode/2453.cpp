class Solution
{
public:
    int destroyTargets(vector<int> &nums, int space)
    {
        sort(nums.begin(), nums.end());
        unordered_map<int, vector<int>> m;
        for (auto num : nums)
        {
            m[num % space].push_back(num);
        }
        int max_len = 0, ans = INT_MAX;
        for (auto it : m)
        {
            const auto &x = it.second;
            if (x.size() >= max_len)
            {
                auto new_min = x[0];
                if (x.size() > max_len || new_min < ans)
                {
                    max_len = x.size();
                    ans = new_min;
                }
            }
        }
        return ans;
    }
};