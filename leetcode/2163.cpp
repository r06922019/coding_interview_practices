class Solution
{
public:
    long long minimumDifference(vector<int> &nums)
    {
        priority_queue<int> pq1_max;
        const int n = nums.size() / 3;
        vector<long long> ans1(n + 1, 0);
        long long cur_ans1 = 0;
        for (int i = 0; i < n; ++i)
        {
            pq1_max.push(nums[i]);
            cur_ans1 += nums[i];
        }
        ans1[0] = cur_ans1;
        for (int i = n; i < 2 * n; ++i)
        {
            cur_ans1 += nums[i];
            pq1_max.push(nums[i]);
            cur_ans1 -= pq1_max.top();
            pq1_max.pop();
            ans1[i - n + 1] = cur_ans1;
        }

        reverse(nums.begin(), nums.end());

        auto cmp = [](const int a, const int b)
        { return a > b; };
        priority_queue<int, vector<int>, decltype(cmp)> pq2_min(cmp);
        vector<long long> ans2(n + 1, 0);
        long long cur_ans2 = 0;
        for (int i = 0; i < n; ++i)
        {
            pq2_min.push(nums[i]);
            cur_ans2 += nums[i];
        }
        ans2[0] = cur_ans2;
        for (int i = n; i < 2 * n; ++i)
        {
            cur_ans2 += nums[i];
            pq2_min.push(nums[i]);
            cur_ans2 -= pq2_min.top();
            pq2_min.pop();
            ans2[i - n + 1] = cur_ans2;
        }

        reverse(nums.begin(), nums.end());
        reverse(ans2.begin(), ans2.end());
        long long ans = 1e13;
        for (int i = 0; i <= n; ++i)
        {
            ans = min(ans, ans1[i] - ans2[i]);
        }
        return ans;
    }
};

// [16,46,43,41,42,14,36,49,50,28,38,25,17,5,18,11,14,21,23,39,23] should be 14