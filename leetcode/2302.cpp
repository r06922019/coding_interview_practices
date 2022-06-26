class Solution
{
public:
#define ll long long
    long long countSubarrays(vector<int> &nums, long long k)
    {
        vector<ll> prefix_sum = {0};
        for (auto num : nums)
        {
            prefix_sum.push_back(prefix_sum.back() + num);
        }
        ll ans = 0;
        for (int l = 0, r = 0; r < prefix_sum.size(); ++r)
        {
            while ((prefix_sum[r] - prefix_sum[l]) * (ll)(r - l) >= k)
            {
                ++l;
            }
            ans += r - l;
        }
        return ans;
    }
};