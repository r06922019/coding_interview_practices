class Solution
{
public:
    vector<int> gen_cum_sums(const vector<int> &nums)
    {
        vector<int> ans = {0};
        for (const auto x : nums)
            ans.push_back(ans.back() + x);
        return ans;
    }
    int find_ans(vector<int> &cum_sums, const int q)
    {
        int l = 0, r = cum_sums.size();
        while (l < r)
        {
            int mid = l + (r - l) / 2;
            if (cum_sums[mid] <= q)
                l = mid + 1;
            else
                r = mid;
        }
        return l - 1;
    }
    vector<int> answerQueries(vector<int> &nums, vector<int> &queries)
    {
        vector<int> ans;
        sort(nums.begin(), nums.end());
        auto cum_sums = gen_cum_sums(nums);
        for (auto q : queries)
        {
            ans.push_back(find_ans(cum_sums, q));
        }
        return ans;
    }
};