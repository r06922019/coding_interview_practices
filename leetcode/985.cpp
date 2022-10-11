class Solution
{
public:
    vector<int> sumEvenAfterQueries(vector<int> &nums, vector<vector<int>> &queries)
    {
        vector<int> ans;
        int even_sum = 0, odd_sum = 0;
        for (auto num : nums)
        {
            if (num % 2 == 0)
                even_sum += num; // even_sum += num * ((num & 1) ^ 1);
            // else odd_sum += num;
        }
        for (auto q : queries)
        {
            // assert(q.size() ==2);
            const auto index = q[1], diff = q[0];
            int &num = nums[index];
            if (num % 2 == 0)
                even_sum -= num; // even_sum -= num * ((num & 1) ^ 1);
            // else odd_sum -= num;
            num += diff;
            if (num % 2 == 0)
                even_sum += num; // even_sum += num * ((num & 1) ^ 1);
            // else odd_sum += num;
            ans.push_back(even_sum);
        }

        return ans;
    }
};