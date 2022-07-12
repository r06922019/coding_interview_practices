class Solution
{
public:
    long long minSumSquareDiff(vector<int> &nums1, vector<int> &nums2, int k1, int k2)
    {
        unordered_map<int, int> diff_counts;
        int max_key = 0;
        for (int n = nums1.size(), i = 0; i < n; ++i)
        {
            auto k = (abs(nums1[i] - nums2[i]));
            ++diff_counts[k];
            max_key = max(k, max_key);
        }
        int budget = k1 + k2;
        for (int i = max_key; i > 0; --i)
        {
            if (budget >= diff_counts[i])
            {
                auto x = diff_counts[i];
                budget -= x;
                diff_counts[i] = 0;
                diff_counts[i - 1] += x;
            }
            else
            {
                diff_counts[i] -= budget;
                diff_counts[i - 1] += budget;
                budget = 0;
                break;
            }
        }
        long long ans = 0;
        for (auto p : diff_counts)
        {
            long long tmp = p.first;
            // printf("%d, %d\n", p.first, p.second);
            ans = ans + tmp * tmp * p.second;
        }
        return ans;
    }
};